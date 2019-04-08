<?php

/**
 * @file
 * Campagnes.
 */

/**
 * Returns the list of steps and their associated forms.
 */
function ldlm_survey_campaign_form_steps() {
  return [
    1 => ['form' => 'ldlm_survey_campaign_form_general'],
    2 => ['form' => 'ldlm_survey_campaign_form_campaign_group'],
    3 => ['form' => 'ldlm_survey_campaign_form_participants'],
    4 => ['form' => 'ldlm_survey_campaign_form_participants_confirm'],
  ];
}

/**
 * Formulaire (primaire) d'édition d'une campagne.
 */
function ldlm_survey_campaign_form($form, &$form_state, $campaign = NULL) {
  if (!isset($form_state['storage']['campaign'])) {
    if (!$campaign) {
      $campaign = entity_create('campaign', []);
    }
    $form_state['storage']['campaign'] = $campaign;
  }

  // Initialize a description of the steps for the wizard.
  if (empty($form_state['step'])) {
    $form_state['step'] = 1;

    // This array contains the function to be called at each step to get the
    // relevant form elements. It will also store state information for each
    // step.
    $form_state['step_information'] = ldlm_survey_campaign_form_steps();
    $form_state['step_count'] = count($form_state['step_information']);
  }
  $step = &$form_state['step'];
  $step_count = $form_state['step_count'];
  $campaign = &$form_state['storage']['campaign'];
  drupal_set_title(t("Campagne d'évaluation (@step/@total)", [
    '@step' => $step,
    '@total' => $step_count,
  ]));

  // Call the function named in $form_state['step_information'] to get the
  // form elements to display for this step.
  $form = $form_state['step_information'][$step]['form']($form, $form_state);

  // Cas où aucun formulaire n'a été créé.
  if (isset($form['advice'])) {
    return $form;
  }

  // Show the 'previous' button if appropriate. Note that #submit is set to
  // a special submit handler, and that we use #limit_validation_errors to
  // skip all complaints about validation when using the back button. The
  // values entered will be discarded, but they will not be validated, which
  // would be annoying in a "back" button.
  if ($step > 1) {
    $form['prev'] = [
      '#type' => 'submit',
      '#value' => t('Previous'),
      '#name' => 'prev',
      '#submit' => ['ldlm_survey_campaign_form_previous_submit'],
      '#limit_validation_errors' => [],
    ];
  }

  // Show the Next button only if there are more steps defined.
  if ($step < $step_count) {
    // The Next button should be included on every step.
    $form['next'] = [
      '#type' => 'submit',
      '#value' => t('Next'),
      '#name' => 'next',
      '#submit' => ['ldlm_survey_campaign_form_next_submit'],
    ];
  }
  else {
    // Just in case there are no more steps, we use the default submit handler
    // of the form wizard. Call this button Finish, Submit, or whatever you
    // want to show. When this button is clicked, the
    // form_example_wizard_submit handler will be called.
    $form['finish'] = [
      '#type' => 'submit',
      '#value' => t('Finish'),
    ];
  }

  // Include each validation function defined for the different steps.
  if (function_exists($form_state['step_information'][$step]['form'] . '_validate')) {
    $form['next']['#validate'] = array($form_state['step_information'][$step]['form'] . '_validate');
  }

  return $form;
}

/**
 * Submit handler for the "previous" button.
 *
 * This function:
 * - Stores away $form_state['values']
 * - Decrements the step counter
 * - Replaces $form_state['values'] with the values from the previous state.
 * - Forces form rebuild.
 *
 * You are not required to change this function.
 *
 * @ingroup form_example
 */
function ldlm_survey_campaign_form_previous_submit($form, &$form_state) {
  $current_step = &$form_state['step'];
  $form_state['step_information'][$current_step]['stored_values'] = $form_state['input'];
  if ($current_step > 1) {
    $current_step--;
    $form_state['values'] = $form_state['step_information'][$current_step]['stored_values'];
  }
  $form_state['rebuild'] = TRUE;
}

/**
 * Submit handler for the 'next' button.
 *
 * This function:
 * - Saves away $form_state['values']
 * - Increments the step count.
 * - Replace $form_state['values'] from the last time we were at this page
 *   or with array() if we haven't been here before.
 * - Force form rebuild.
 *
 * You are not required to change this function.
 *
 * @ingroup form_example
 */
function ldlm_survey_campaign_form_next_submit($form, &$form_state) {
  $current_step = &$form_state['step'];
  $form_state['step_information'][$current_step]['stored_values'] = $form_state['values'];

  if ($current_step < count($form_state['step_information'])) {
    $current_step++;
    if (!empty($form_state['step_information'][$current_step]['stored_values'])) {
      $form_state['values'] = $form_state['step_information'][$current_step]['stored_values'];
    }
    else {
      $form_state['values'] = array();
    }
    // Force rebuild with next step.
    $form_state['rebuild'] = TRUE;
    return;
  }
}

/**
 * Informations générales sur la campagne.
 */
function ldlm_survey_campaign_form_general($form, &$form_state) {
  $form = [];

  // Forcer à créer un questionnaire auparavant.
  if (!ldlm_survey_get_surveys()) {
    $form['advice'] = [
      '#markup' => t('Vous devez <a href="!url">créer un questionnaire</a> avant de créer une campagne.', [
        '!url' => url('admin/content/survey/survey/add'),
      ]),
    ];

    return $form;
  }

  $form['title'] = [
    '#type' => 'textfield',
    '#title' => t('Titre'),
    '#description' => t("Nom de la campagne d'évaluation."),
    '#required' => TRUE,
    '#default_value' => !empty($form_state['values']['title']) ? $form_state['values']['title'] : '',
  ];
  $default_timezone = date_default_timezone();
  $form['begin'] = [
    '#type' => 'date_popup',
    '#date_type' => DATE_DATETIME,
    '#date_timezone' => $default_timezone,
    '#date_format' => 'd/m/Y',
    '#date_year_range' => '0:+1',
    '#date_label_position' => 'none',
    '#datepicker_options' => [
      'minDate' => 1,
    ],
    '#title' => t('Ouverture de la campagne'),
    '#required' => TRUE,
    '#default_value' => !empty($form_state['values']['begin']) ? $form_state['values']['begin'] : NULL,
  ];
  $form['end'] = [
    '#type' => 'date_popup',
    '#date_type' => DATE_DATETIME,
    '#date_timezone' => $default_timezone,
    '#date_format' => 'd/m/Y',
    '#date_year_range' => '0:+1',
    '#date_label_position' => 'none',
    '#datepicker_options' => [
      'minDate' => 2,
    ],
    '#title' => t('Fermeture de la campagne'),
    '#required' => TRUE,
    '#default_value' => !empty($form_state['values']['end']) ? $form_state['values']['end'] : NULL,
  ];
  $form['token'] = [
    '#type' => 'machine_name',
    '#title' => t("Clef d'accès"),
    '#description' => t("Nom unique compréhensible par une machine. Peut seulement contenir des lettres minuscules, chiffres, et tirets bas (_). Cette chaîne est utilisée pour générer un lien d'accès utilisable par l'ensemble des participants (moyennant la saisie d'une adresse électronique personnelle), dans le cas où ils ne peuvent pas utiliser le lien personnel envoyé par courriel. Laisser vide pour désactiver cette fonctionnalité."),
    '#maxlength' => 100,
    '#machine_name' => ['exists' => 'campaign_token_load'],
    '#default_value' => !empty($form_state['values']['token']) ? $form_state['values']['token'] : '',
  ];

  return $form;
}

/**
 * Informations générales sur la campagne (validation).
 */
function ldlm_survey_campaign_form_general_validate($form, &$form_state) {
  if ($form_state['values']['begin'] >= $form_state['values']['end']) {
    form_set_error('begin', t("La date de fermeture de la campagne doit être postérieure à la date d'ouverture."));
  }
}

/**
 * Choix ou création du groupe de campagnes.
 */
function ldlm_survey_campaign_form_campaign_group($form, &$form_state) {
  $form = [];
  $survey_options = ldlm_survey_get_surveys_as_options();
  $campaign_group_options = ldlm_survey_get_campaign_groups_as_options();

  $form['survey_mode'] = [
    '#type' => 'radios',
    '#title' => t('Mode de création'),
    '#options' => [
      'campaign_group' => t('Utiliser un groupe de campagnes existant.'),
      'survey' => t('Créer un nouveau groupe de campagnes.'),
    ],
    '#required' => TRUE,
  ];
  $form['survey'] = [
    '#type' => 'select',
    '#title' => t('Formulaire'),
    '#description' => t('Formulaire à utiliser pour cette campagne. Un nouveau groupe de campagnes sera automatiquement créé.'),
    '#options' => $survey_options,
    '#states' => [
      'visible' => [
        ':input[name="survey_mode"]' => ['value' => 'survey'],
      ],
      'required' => [
        ':input[name="survey_mode"]' => ['value' => 'survey'],
      ],
    ],
    '#default_value' => !empty($form_state['values']['survey']) ? $form_state['values']['survey'] : NULL,
  ];
  $form['campaign_group_title'] = [
    '#type' => 'textfield',
    '#title' => t('Nom du groupe de campagnes'),
    '#description' => t("Nom à donner au groupe de campagnes. Utile pour le retrouver facilement à l'occasion de la création d'une campagne ultérieure."),
    '#states' => [
      'visible' => [
        ':input[name="survey_mode"]' => ['value' => 'survey'],
      ],
      'required' => [
        ':input[name="survey_mode"]' => ['value' => 'survey'],
      ],
    ],
    '#default_value' => !empty($form_state['values']['campaign_group_title']) ? $form_state['values']['campaign_group_title'] : '',
  ];
  $form['campaign_group'] = [
    '#type' => 'select',
    '#title' => t('Groupe de campagnes'),
    '#description' => t('Groupe de campagnes à réutiliser.'),
    '#options' => $campaign_group_options,
    '#states' => [
      'visible' => [
        ':input[name="survey_mode"]' => ['value' => 'campaign_group'],
      ],
      'required' => [
        ':input[name="survey_mode"]' => ['value' => 'campaign_group'],
      ],
    ],
    '#default_value' => !empty($form_state['values']['campaign_group']) ? $form_state['values']['campaign_group'] : NULL,
  ];
  if (count($campaign_group_options) == 1) {
    unset($form['survey_mode']['#options']['campaign_group']);
    $form['survey_mode']['#default_value'] = 'survey';
    $form['campaign_group']['#disabled'] = TRUE;
  }
  else {
    $form['survey_mode']['#default_value'] = !empty($form_state['values']['survey_mode']) ? $form_state['values']['survey_mode'] : 'campaign_group';
  }

  return $form;
}

/**
 * Choix ou création du groupe de campagnes (validation).
 */
function ldlm_survey_campaign_form_campaign_group_validate($form, &$form_state) {
  $survey_mode = $form_state['values']['survey_mode'];
  if ($form_state['values'][$survey_mode] == '_none') {
    form_set_error($survey_mode, t('Veuillez choisir un formulaire ou un groupe de campagnes.'));
  }
  if ($survey_mode == 'survey' && empty($form_state['values']['campaign_group_title'])) {
    form_set_error('campaign_group_title', t('Veuillez saisir un nom pour le groupe de campagnes à créer.'));
  }
}

/**
 * Importation des participants.
 */
function ldlm_survey_campaign_form_participants($form, &$form_state) {
  $form = [];

  $form['csv'] = [
    '#type' => 'managed_file',
    '#title' => t('Liste des participants'),
    '#description' => t("Fichiers au format CSV contenant la liste des participants à cette campagne : <ul><li>colonnes dans cet ordre : nom, prénom, courriel,</li><li>le séparateur est le point-virgule,</li><li>la première ligne n'est pas prise en compte,</li><li>le fichier est encodé en UTF-8, et a pour extension <code>.csv</code>.</li></ul>"),
    '#default_value' => !empty($form_state['storage']['csv']) ? $form_state['storage']['csv'] : 0,
    '#upload_location' => 'private://',
    '#upload_validators' => [
      'file_validate_extensions' => ['csv'],
    ],
  ];

  return $form;
}

/**
 * Importation des participants (validation).
 */
function ldlm_survey_campaign_form_participants_validate($form, &$form_state) {
  $form_state['storage']['csv'] = $form_state['values']['csv'];
  if ($file = file_load($form_state['storage']['csv'])) {
    if (!($participants = ldlm_survey_campaign_read_participants_csv($file->uri))) {
      form_set_error('csv', t('Le fichier @file est vide ou invalide.', ['@file' => $file->uri]));
    }
    else {
      $form_state['storage']['participants'] = $participants;
    }
  }
  else {
    form_set_error('csv', t("Le fichier @file n'a pas pu être chargé.", ['@file' => $file->uri]));
  }
}

/**
 * Confirmation de l'importation des participants.
 */
function ldlm_survey_campaign_form_participants_confirm($form, &$form_state) {
  $form = [];

  $form['recap_participants'] = [
    [
      '#theme' => 'html_tag',
      '#tag' => 'h2',
      '#value' => t('Récapitulatif des participants'),
    ],
    [
      '#theme' => 'table',
      '#header' => [t('Nom'), t('Prénom'), t('Courriel')],
      '#rows' => $form_state['storage']['participants'],
    ],
    [
      '#theme' => 'html_tag',
      '#tag' => 'p',
      '#value' => t("Si la liste est incorrecte, revenez à l'écran précédent pour charger un nouveau fichier. Validez ce formulaire pour créer la campagne."),
    ],
  ];

  return $form;
}

/**
 * Fin du formulaire et création ou mise à jour de la campagne.
 */
function ldlm_survey_campaign_form_submit($form, &$form_state) {
  $current_step = &$form_state['step'];
  $form_state['step_information'][$current_step]['stored_values'] = $form_state['values'];

  // Groupe de campagne.
  if ($form_state['step_information'][2]['stored_values']['survey_mode'] == 'campaign_group') {
    $campaign_group = campaign_group_load($form_state['step_information'][2]['stored_values']['campaign_group']);
  }
  else {
    $campaign_group = entity_create('campaign_group', [
      'sid' => $form_state['step_information'][2]['stored_values']['survey'],
      'title' => $form_state['step_information'][2]['stored_values']['campaign_group_title'],
    ]);
    $campaign_group->save();
  }

  // Campagne.
  $campaign = $form_state['storage']['campaign'];
  $campaign->cgid = $campaign_group->cgid;
  $campaign->title = $form_state['step_information'][1]['stored_values']['title'];
  $campaign->begin = strtotime($form_state['step_information'][1]['stored_values']['begin']);
  $campaign->end = strtotime($form_state['step_information'][1]['stored_values']['end']);
  $campaign->token = $form_state['step_information'][1]['stored_values']['token'];
  $campaign->save();

  // Participants.
  foreach ($form_state['storage']['participants'] as $participant_value) {
    $participant = entity_create('participant', [
      'cid' => $campaign->cid,
      'mail' => $participant_value['mail'],
      'surname' => $participant_value['surname'],
      'name' => $participant_value['name'],
    ]);
    $participant->save();
  }

  drupal_set_message(t('La campagne %title a été enregistrée', ['%title' => $campaign->title]));
}

/**
 * Lire le fichier CSV contenant la liste des participants.
 */
function ldlm_survey_campaign_read_participants_csv($uri) {
  $delimiter = ';';
  $participants = $mails = [];
  $headers = ['surname', 'name', 'mail'];

  if ($handle = fopen($uri, 'r')) {
    $i = 0;
    while (($line = fgetcsv($handle, 0, $delimiter)) !== FALSE) {
      $i++;
      if ($i == 1) {
        continue;
      }
      if (count($line) != 3) {
        $participants = [];
        drupal_set_message(t('Le fichier CSV doit contenir exactement trois colonnes séparées par des points-virgules, dans cet ordre : nom, prénom, courriel.'), 'error');
        break;
      }
      $mail = $line[2];
      if (!valid_email_address($mail)) {
        $participants = [];
        drupal_set_message(t('Le courriel @mail est incorrect (ligne @line).', ['@mail' => $mail, '@line' => $i]), 'error');
        break;
      }
      if (isset($mails[$mail])) {
        $participants = [];
        drupal_set_message(t('Le courriel @mail est déjà utilisé (ligne @line).', ['@mail' => $mail, '@line' => $i]), 'error');
        break;
      }
      $participants[] = array_combine($headers, $line);
      $mails[$mail] = $mail;
    }
    fclose($handle);
  }
  else {
    drupal_set_message(t("Le fichier @file n'a pas pu être ouvert.", ['@file' => $uri]), 'error');
  }

  return $participants;
}

/**
 * Formulaire de confirmation de suppression d'une campagne.
 */
function ldlm_survey_campaign_delete_confirm($form, &$form_state, $campaign) {
  $form['#campaign'] = $campaign;
  return confirm_form($form, t('Êtes-vous sûr·e de vouloir supprimer la campagne %title ?', ['%title' => $campaign->title]), 'admin/content/survey/campaign');
}

/**
 * Soumission formulaire de confirmation de suppression d'une campagne (submit).
 */
function ldlm_survey_campaign_delete_confirm_submit($form, &$form_state) {
  $campaign = $form['#campaign'];
  $campaign->delete();
  watchdog('ldlm_survey', 'Campagne %title supprimé', ['%title' => $campaign->title]);
  drupal_set_message(t('Campagne %title supprimé', ['%title' => $campaign->title]));
  $form_state['redirect'] = 'admin/content/survey/campaign';
}

/**
 * Export des participants en CSV.
 */
function ldlm_survey_export_participants($campaign) {
  $delimiter = ';';
  $header = [t('Nom'), t('Prénom'), t('Courriel')];

  drupal_add_http_header('Content-Type', 'text/csv; utf-8');
  drupal_add_http_header('Content-Disposition', 'attachment; filename=participants_' . $campaign->cid . '.csv');
  $handle = fopen('php://output', 'w');
  fputcsv($handle, $header, $delimiter);
  foreach ($campaign->getParticipants() as $participant) {
    $line = [$participant->surname, $participant->name, $participant->mail];
    fputcsv($handle, $line, $delimiter);
  }
  fclose($handle);
  drupal_exit();
}
