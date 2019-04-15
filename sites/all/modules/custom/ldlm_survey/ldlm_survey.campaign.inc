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
  $campaign = $form_state['storage']['campaign'];

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
    '#default_value' => !empty($form_state['values']['title']) ? $form_state['values']['title'] : (isset($campaign->title) ? $campaign->title : ''),
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
    '#description' => t("À cette date, la campagne passera de l'état <em>programmée</em> à l'état <em>en cours</em> et <strong>ne sera plus modifiable</strong>. Les participants recevront un courriel les avertissant de l'ouverture de la campagne, qui contiendra un lien leur permettant d'accéder directement au formulaire d'évaluation."),
    '#required' => TRUE,
    '#default_value' => !empty($form_state['values']['begin']) ? $form_state['values']['begin'] : (isset($campaign->begin) ? date('Y-m-d', $campaign->begin) : NULL),
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
    '#default_value' => !empty($form_state['values']['end']) ? $form_state['values']['end'] : (isset($campaign->end) ? date('Y-m-d', $campaign->end) : NULL),
  ];
  $form['token'] = [
    '#type' => 'machine_name',
    '#title' => t("Clef d'accès"),
    '#description' => t("Nom unique compréhensible par une machine. Peut seulement contenir des lettres minuscules, chiffres, et tirets bas (_). Cette chaîne est utilisée pour générer un lien d'accès utilisable par l'ensemble des participants (moyennant la saisie d'une adresse électronique personnelle), dans le cas où ils ne peuvent pas utiliser le lien personnel envoyé par courriel. Laisser vide pour désactiver cette fonctionnalité."),
    '#maxlength' => 100,
    '#machine_name' => ['exists' => 'campaign_token_load'],
    '#default_value' => !empty($form_state['values']['token']) ? $form_state['values']['token'] : (isset($campaign->token) ? $campaign->token : ''),
  ];

  return $form;
}

/**
 * Informations générales sur la campagne (validation).
 */
function ldlm_survey_campaign_form_general_validate($form, &$form_state) {
  if (strtotime($form_state['values']['begin']) <= REQUEST_TIME) {
    form_set_error('begin', t("Veuillez choisir une date future pour l'ouverture de la campagne."));
  }
  if ($form_state['values']['begin'] >= $form_state['values']['end']) {
    form_set_error('begin', t("La date de fermeture de la campagne doit être postérieure à la date d'ouverture."));
  }
}

/**
 * Choix ou création du groupe de campagnes.
 */
function ldlm_survey_campaign_form_campaign_group($form, &$form_state) {
  $form = [];
  $campaign = $form_state['storage']['campaign'];
  $survey_options = ldlm_survey_get_surveys_as_options();
  $campaign_group_options = ldlm_survey_get_campaign_groups_as_options();

  $form['survey_mode'] = [
    '#type' => 'radios',
    '#title' => t('Mode de création'),
    '#description' => t("Un groupe de campagnes permet de lancer plusieurs campagnes utilisant le même questionnaire et d'en exploiter conjointement les résultats."),
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
    '#default_value' => !empty($form_state['values']['campaign_group']) ? $form_state['values']['campaign_group'] : (isset($campaign->cgid) ? $campaign->cgid : NULL),
  ];
  // Si aucun groupe de questions existants, forcer à en créer un.
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
  $campaign = $form_state['storage']['campaign'];

  $form['csv'] = [
    '#type' => 'managed_file',
    '#title' => t('Liste des participants'),
    '#description' => t("Fichiers au format CSV contenant la liste des participants à cette campagne : <ul><li>colonnes dans cet ordre : nom, prénom, courriel,</li><li>le séparateur est le point-virgule,</li><li>la première ligne n'est pas prise en compte,</li><li>le fichier est encodé en UTF-8, et a pour extension <code>.csv</code>.</li></ul>"),
    '#required' => TRUE,
    '#default_value' => !empty($form_state['storage']['csv']) ? $form_state['storage']['csv'] : (isset($campaign->csv) ? $campaign->csv : 0),
    '#upload_location' => 'private://survey/campaign/csv/' . date('Y/m'),
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

  // Nettoyer pour la prévisualisation, mais enregistrer les données telles
  // quelles.
  $participants = $form_state['storage']['participants'];
  array_walk_recursive($participants, function (&$item, $key) {
    $item = check_plain($item);
  });

  $form['recap_participants'] = [
    [
      '#theme' => 'html_tag',
      '#tag' => 'h2',
      '#value' => t('Récapitulatif des participants'),
    ],
    [
      '#theme' => 'table',
      '#header' => [t('Nom'), t('Prénom'), t('Courriel')],
      '#rows' => $participants,
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
  $campaign = $form_state['storage']['campaign'];
  $import_participants = TRUE;

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

  // Si le groupe de campagnes change, supprimer l'ancien s'il ne contenait plus
  // que cette campagne pour éviter les groupes de campagnes orphelins.
  if (isset($campaign->cgid) && $campaign->cgid != $campaign_group->cgid) {
    $old_campaign_group = campaign_group_load($campaign->cgid);
    if (count($old_campaign_group->getCampaigns()) == 1) {
      $old_campaign_group->delete();
    }
  }

  // Si le CSV change, supprimer tous les participants pour les réimporter plus
  // tard, et supprimer l'ancien fichier.
  if (isset($campaign->csv)) {
    if ($campaign->csv != $form_state['storage']['csv']) {
      $campaign->deleteParticipants();
      $campaign->deleteCsv();
    }
    else {
      $import_participants = FALSE;
    }
  }

  // Campagne.
  $campaign->cgid = $campaign_group->cgid;
  $campaign->title = $form_state['step_information'][1]['stored_values']['title'];
  $campaign->begin = strtotime($form_state['step_information'][1]['stored_values']['begin']);
  $campaign->end = strtotime($form_state['step_information'][1]['stored_values']['end']);
  $campaign->token = $form_state['step_information'][1]['stored_values']['token'];
  $campaign->csv = $form_state['storage']['csv'];
  $campaign->save();

  // Enregistrer le fichier CSV comme permanent.
  $file = file_load($form_state['storage']['csv']);
  $file->status = FILE_STATUS_PERMANENT;
  file_save($file);
  file_usage_add($file, 'ldlm_survey', 'campaign', $campaign->cid);

  // Participants.
  if ($import_participants) {
    foreach ($form_state['storage']['participants'] as $participant_value) {
      $participant = entity_create('participant', [
        'cid' => $campaign->cid,
        'mail' => $participant_value['mail'],
        'surname' => $participant_value['surname'],
        'name' => $participant_value['name'],
      ]);
      $participant->save();
    }
  }

  drupal_set_message(t('La campagne %title a été enregistrée', ['%title' => $campaign->title]));
  $form_state['redirect'] = 'admin/content/survey/campaign/' . $campaign->cid;
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
function ldlm_survey_export_participants($campaign, $links = FALSE) {
  $delimiter = ';';
  $header = [t('Nom'), t('Prénom'), t('Courriel')];
  if ($links) {
    $header[] = t("Lien");
  }

  drupal_add_http_header('Content-Type', 'text/csv; utf-8');
  drupal_add_http_header('Content-Disposition', 'attachment; filename=participants_' . $campaign->cid . '.csv');
  $handle = fopen('php://output', 'w');
  fputcsv($handle, $header, $delimiter);
  foreach ($campaign->getParticipants() as $participant) {
    $line = [$participant->surname, $participant->name, $participant->mail];
    if ($links) {
      $line[] = url('evaluation/' . $participant->hash, ['absolute' => TRUE]);
    }
    fputcsv($handle, $line, $delimiter);
  }
  fclose($handle);
  drupal_exit();
}

/**
 * Title callback.
 */
function ldlm_survey_campaign_page_title($campaign) {
  return $campaign->title;
}

/**
 * Tableau de bord d'une campagne.
 */
function ldlm_survey_campaign_page($campaign) {
  $wr_campaign = $campaign->wrapper();
  if ($results = $campaign->getResults(FALSE, TRUE)) {
    $results = reset($results['survey']);
  }
  $data = [
    [
      t('État'),
      $wr_campaign->status->label(),
    ],
    [
      t('Taux de réponse'),
      theme('answered_ratio', $campaign->getAnsweredRatio()),
    ],
    [
      t('Moyenne globale'),
      $results ? theme('survey_value', $results['avg']) : t('N/A'),
    ],
    [
      t('Écart type global'),
      $results ? theme('survey_value', $results['stddev']) : t('N/A'),
    ],
    [
      t("Date d'ouverture de la campagne"),
      date('Y-m-d', $campaign->begin),
    ],
    [
      t("Date de fermeture de la campagne"),
      date('Y-m-d', $campaign->end),
    ],
    [
      t("Date de création de la campagne"),
      date('Y-m-d', $campaign->created),
    ],
    [
      t("Date de modification de la campagne"),
      date('Y-m-d', $campaign->changed),
    ],
    [
      t('Groupe de campagnes'),
      $wr_campaign->cgid->title->value(['sanitize' => TRUE]),
    ],
    [
      t('Questionnaire'),
      l($wr_campaign->cgid->sid->title->value(['sanitize' => TRUE]), 'admin/content/survey/survey/' . $wr_campaign->cgid->sid->raw() . '/demo'),
    ],
    [
      t("Lien d'accès direct"),
      url('evaluation/direct/' . $campaign->token, ['absolute' => TRUE]),
    ],
  ];
  return [
    '#theme' => 'table',
    '#rows' => $data,
  ];
}

/**
 * Liste des participants.
 */
function ldlm_survey_campaign_participants_page($campaign) {
  $participants = [];

  foreach ($campaign->getParticipants() as $participant) {
    $participants[] = [
      check_plain($participant->surname),
      check_plain($participant->name),
      check_plain($participant->mail),
      $participant->answered ? t('Yes') : t('No'),
    ];
  }

  return [
    [
      '#theme' => 'table',
      '#header' => [t('Nom'), t('Prénom'), t('Courriel'), t('Répondu')],
      '#rows' => $participants,
    ],
    [
      '#theme' => 'item_list',
      '#type' => 'ul',
      '#attributes' => [
        'class' => ['inline'],
      ],
      '#items' => [
        l(t('exporter participants'), 'admin/content/survey/campaign/' . $campaign->cid . '/participants-csv'),
        l(t('exporter liens de connexion'), 'admin/content/survey/campaign/' . $campaign->cid . '/liens-csv'),
      ],
    ],
  ];
}

/**
 * Remarques.
 */
function ldlm_survey_campaign_remarques_page($campaign) {
  $wr_campaign = $campaign->wrapper();
  $survey = $wr_campaign->cgid->sid->value();
  $header = [t('Points positifs'), t('Points à améliorer')];
  $remarques = $campaign->getRemarques();

  if (!$remarques) {
    return t("Pas de remarques pour l'instant.");
  }

  $return = [
    [
      '#theme' => 'html_tag',
      '#tag' => 'p',
      '#value' => t('Ces réponses ont été soumises via le questionnaire <a href="!url">@survey</a>, du !begin au !end.', [
        '@survey' => $survey->title,
        '!url' => url('admin/content/survey/survey/' . $survey->sid . '/demo'),
        '!begin' => date('Y-m-d', $campaign->begin),
        '!end' => date('Y-m-d', $campaign->end),
      ]),
    ],
  ];

  foreach ($survey->getQuestionGroups() as $qgid => $question_group) {
    if (!isset($remarques[$qgid])) {
      continue;
    }
    $return[] = [
      '#theme' => 'html_tag',
      '#tag' => 'h2',
      '#value' => check_plain($question_group->title),
    ];
    $return[] = [
      '#theme' => 'table',
      '#header' => $header,
      '#rows' => $remarques[$qgid],
    ];
  }
  $return[] = [
    '#theme' => 'item_list',
    '#type' => 'ul',
    '#attributes' => [
      'class' => ['inline'],
    ],
    '#items' => [
      l(t('exporter remarques'), 'admin/content/survey/campaign/' . $campaign->cid . '/remarques-csv'),
    ],
  ];

  return $return;
}

/**
 * Export des remarques en CSV.
 */
function ldlm_survey_export_remarques($campaign) {
  $wr_campaign = $campaign->wrapper();
  $survey = $wr_campaign->cgid->sid->value();
  $remarques = $campaign->getRemarques();
  $delimiter = ';';
  $header = [
    t('Groupe de questions'),
    t('Points positifs'),
    t('Points à améliorer'),
  ];

  drupal_add_http_header('Content-Type', 'text/csv; utf-8');
  drupal_add_http_header('Content-Disposition', 'attachment; filename=remarques_' . $campaign->cid . '.csv');
  $handle = fopen('php://output', 'w');
  fputcsv($handle, $header, $delimiter);
  foreach ($survey->getQuestionGroups() as $qgid => $question_group) {
    if (!isset($remarques[$qgid])) {
      continue;
    }
    foreach ($remarques[$qgid] as $comments) {
      $line = [
        $question_group->title,
        $comments['positif'],
        $comments['negatif'],
      ];
      fputcsv($handle, $line, $delimiter);
    }
  }
  fclose($handle);
  drupal_exit();
}

/**
 * Résultat d'une campagne ou de tout un groupe.
 */
function ldlm_survey_campaign_results_page($campaign, $group = FALSE) {
  $wr_campaign = $campaign->wrapper();
  $survey = $wr_campaign->cgid->sid->value();
  $results = $campaign->getResults($group);
  $header = [
    t('Question'),
    t('Moyenne'),
    t('Écart type'),
  ];

  if (!$results) {
    return t("Pas de résultats pour l'instant.");
  }

  if ($group) {
    $message = t('Ces réponses ont été soumises via le questionnaire <a href="!url">@survey</a>, à travers les campagnes du groupe %group.', [
      '@survey' => $survey->title,
      '!url' => url('admin/content/survey/survey/' . $survey->sid . '/demo'),
      '%group' => $wr_campaign->cgid->title->value(),
    ]);
  }
  else {
    $message = t('Ces réponses ont été soumises via le questionnaire <a href="!url">@survey</a>, du !begin au !end.', [
      '@survey' => $survey->title,
      '!url' => url('admin/content/survey/survey/' . $survey->sid . '/demo'),
      '!begin' => date('Y-m-d', $campaign->begin),
      '!end' => date('Y-m-d', $campaign->end),
    ]);
  }
  $return = [
    [
      '#theme' => 'html_tag',
      '#tag' => 'p',
      '#value' => $message,
    ],
    [
      '#theme' => 'html_tag',
      '#tag' => 'p',
      '#value' => t('<strong>Moyenne globale :</strong> !avg', [
        '!avg' => theme('survey_value', $results['survey'][$survey->sid]['avg']),
      ]),
    ],
    [
      '#theme' => 'html_tag',
      '#tag' => 'p',
      '#value' => t('<strong>Écart type global :</strong> !stddev', [
        '!stddev' => theme('survey_value', $results['survey'][$survey->sid]['stddev']),
      ]),
    ],
  ];

  foreach ($survey->getQuestionGroups() as $qgid => $question_group) {
    $rows = [];

    if (!isset($results['question_group'][$qgid])) {
      continue;
    }

    $return[] = [
      '#theme' => 'html_tag',
      '#tag' => 'h2',
      '#value' => check_plain($question_group->title),
    ];

    foreach ($question_group->getQuestions() as $qid => $question) {
      if (!isset($results['question'][$qid])) {
        continue;
      }

      $rows[] = [
        'title' => check_plain($question->label),
        'avg' => theme('survey_value', $results['question'][$qid]['avg']),
        'stddev' => theme('survey_value', $results['question'][$qid]['stddev']),
      ];
    }

    $rows[] = [
      'data' => [
        'title' => t('Ensemble'),
        'avg' => theme('survey_value', $results['question_group'][$qgid]['avg']),
        'stddev' => theme('survey_value', $results['question_group'][$qgid]['stddev']),
      ],
      'class' => ['survey-value', 'group'],
    ];

    $return[] = [
      '#theme' => 'table',
      '#header' => $header,
      '#rows' => $rows,
    ];
  }

  $slug = $group ? 'group' : 'campaign';
  $return[] = [
    '#theme' => 'item_list',
    '#type' => 'ul',
    '#attributes' => [
      'class' => ['inline'],
    ],
    '#items' => [
      l(t('exporter résultats'), 'admin/content/survey/campaign/' . $campaign->cid . '/results/' . $slug . '-csv'),
      l(t('exporter résultats bruts'), 'admin/content/survey/campaign/' . $campaign->cid . '/raw-results/' . $slug . '-csv'),
    ],
  ];

  $return[] = ['#markup' => t("<p>Les questions sont notées comme suit :</p><ul><li>tout à fait d'accord (4 points),</li><li>plutôt d'accord (3 points),</li><li>plutôt pas d'accord (2 points),</li><li>pas du tout d'accord (1 point).</li></ul><p>En conséquence, la moyenne varie également entre 1 et 4 (intervalle d'une largeur de 3 points), tandis que l'écart type, lui, varie de 0 à 1,5. On divise ces intervalles en trois parties égales, et on considère que la moyenne est bonne (vert) au-dessus de 3 et médiocre (rouge) en dessous de 2. L'écart type est médiocre (répartition importante) au-dessus de 1, et bon en dessous de 0,5.</p>")];

  return $return;
}

/**
 * Export CSV des résultats bruts.
 */
function ldlm_survey_export_raw_results($campaign, $group = FALSE) {
  $delimiter = ';';
  $wr_campaign = $campaign->wrapper();
  $survey = $wr_campaign->cgid->sid->value();
  $results = $campaign->getRawResults($group);
  $header = [
    t('Groupe de questions'),
    t('Question'),
    t('Points'),
  ];
  $slug = $group ? 'groupe' : 'campagne';

  drupal_add_http_header('Content-Type', 'text/csv; utf-8');
  drupal_add_http_header('Content-Disposition', 'attachment; filename=resultats_bruts_' . $slug . '_' . $campaign->cid . '.csv');
  $handle = fopen('php://output', 'w');
  fputcsv($handle, $header, $delimiter);

  foreach ($survey->getQuestionGroups() as $qgid => $question_group) {
    foreach ($question_group->getQuestions() as $qid => $question) {
      if (!isset($results['question'][$qid])) {
        continue;
      }
      foreach ($results['question'][$qid] as $count) {
        $line = [
          $question_group->title,
          $question->label,
          reset($count),
        ];
        fputcsv($handle, $line, $delimiter);
      }
    }
  }
  fclose($handle);
  drupal_exit();
}

/**
 * Export CSV des résultats.
 */
function ldlm_survey_export_results($campaign, $group = FALSE) {
  $delimiter = ';';
  $wr_campaign = $campaign->wrapper();
  $survey = $wr_campaign->cgid->sid->value();
  $results = $campaign->getResults($group);
  $header = [
    t('Groupe de questions'),
    t('Question'),
    t('Moyenne'),
    t('Écart type'),
  ];
  $slug = $group ? 'groupe' : 'campagne';

  drupal_add_http_header('Content-Type', 'text/csv; utf-8');
  drupal_add_http_header('Content-Disposition', 'attachment; filename=resultats_' . $slug . '_' . $campaign->cid . '.csv');
  $handle = fopen('php://output', 'w');
  fputcsv($handle, $header, $delimiter);

  foreach ($survey->getQuestionGroups() as $qgid => $question_group) {
    foreach ($question_group->getQuestions() as $qid => $question) {
      if (!isset($results['question'][$qid])) {
        continue;
      }
      $line = [
        $question_group->title,
        $question->label,
        number_format($results['question'][$qid]['avg']['value'], 1, ',', ''),
        number_format($results['question'][$qid]['stddev']['value'], 1, ',', ''),
      ];
      fputcsv($handle, $line, $delimiter);
    }
  }
  fclose($handle);
  drupal_exit();
}
