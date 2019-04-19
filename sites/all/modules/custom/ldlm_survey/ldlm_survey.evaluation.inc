<?php

/**
 * @file
 * Réponses aux évaluations.
 */

/**
 * Prologue du formulaire d'évaluation.
 */
function ldlm_survey_evaluation_prologue_form($form, &$form_state, $campaign) {
  $form = [];

  drupal_set_title($campaign->title);

  $form['#campaign'] = $campaign;
  $form['mail'] = [
    '#type' => 'textfield',
    '#title' => t('Adresse électronique'),
    '#required' => TRUE,
  ];
  $form['actions'] = ['#type' => 'actions'];
  $form['actions']['submit'] = [
    '#type' => 'submit',
    '#value' => t("Participer à l'enquête"),
    '#name' => 'submit',
  ];

  return $form;
}

/**
 * Prologue du formulaire d'évaluation (validation).
 */
function ldlm_survey_evaluation_prologue_form_validate($form, &$form_state) {
  $campaign = $form['#campaign'];

  $query = new EntityFieldQuery();
  $result = $query->entityCondition('entity_type', 'participant')
    ->propertyCondition('cid', $campaign->cid)
    ->propertyCondition('mail', trim($form_state['values']['mail']))
    ->execute();

  if (!empty($result['participant'])) {
    $pids = array_keys($result['participant']);
    $pid = reset($pids);
    $participant = participant_load($pid);
  }
  else {
    form_set_error('mail', t("L'adresse électronique saisie n'est pas associée à cette enquête."));
    return;
  }

  if ($participant->answered) {
    form_set_error('mail', t('Vous avez déjà répondu à cette enquête.'));
    return;
  }

  $form_state['storage']['participant'] = $participant;
}

/**
 * Prologue du formulaire d'évaluation (submit).
 */
function ldlm_survey_evaluation_prologue_form_submit($form, &$form_state) {
  $participant = $form_state['storage']['participant'];
  $form_state['redirect'] = 'evaluation/' . $participant->hash;
}

/**
 * Formulaire d'évaluation.
 */
function ldlm_survey_evaluation_form($form, &$form_state, $participant) {
  $form = [];

  if (empty($participant->demo)) {
    $wr_participant = $participant->wrapper();
    $campaign = $wr_participant->cid->value();
    $survey = $wr_participant->cid->cgid->sid->value();
  }
  else {
    $campaign = $participant->demo['campaign'];
    $survey = $participant->demo['survey'];
  }
  $question_options = ldlm_survey_points();

  drupal_set_title($campaign->title);

  $form['#participant'] = $participant;
  $form['#campaign'] = $campaign;
  $form['#survey'] = $survey;
  $form['#tree'] = TRUE;

  $form['header'] = [
    '#theme' => 'html_tag',
    '#tag' => 'p',
    '#value' => t('Bonjour @prenom @nom, merci pour votre participation à cette évaluation. Vos réponses seront anonymisées.', [
      '@prenom' => $participant->name,
      '@nom' => $participant->surname,
    ]),
  ];
  $form['question_groups'] = ['#type' => 'container'];
  foreach ($survey->getQuestionGroups() as $qgid => $question_group) {
    $form['question_groups'][$qgid] = [
      '#type' => 'fieldset',
      '#title' => check_plain($question_group->title),
      '#attributes' => [
        'class' => ['question-group'],
      ],
    ];
    foreach ($question_group->getQuestions() as $qid => $question) {
      $form['question_groups'][$qgid]['questions'][$qid] = [
        '#type' => 'radios',
        '#title' => check_plain($question->label),
        '#required' => TRUE,
        '#options' => $question_options,
      ];
    }
    $form['question_groups'][$qgid]['remarques'] = [
      '#type' => 'fieldset',
      '#title' => t('Remarques, commentaires ou suggestions'),
      '#attributes' => [
        'class' => ['remarques'],
      ],
    ];
    $form['question_groups'][$qgid]['remarques']['positif'] = [
      '#type' => 'textarea',
      '#title' => t('Points positifs'),
      '#maxlength_js' => TRUE,
      '#maxlength' => 500,
    ];
    $form['question_groups'][$qgid]['remarques']['negatif'] = [
      '#type' => 'textarea',
      '#title' => t('Points à améliorer'),
      '#maxlength_js' => TRUE,
      '#maxlength' => 500,
    ];
  }

  $form['actions'] = ['#type' => 'actions'];
  $form['actions']['submit'] = [
    '#type' => 'submit',
    '#value' => t("Envoyer"),
    '#name' => 'submit',
    '#disabled' => !empty($participant->demo),
  ];

  return $form;
}

/**
 * Formulaire d'évaluation (submit).
 */
function ldlm_survey_evaluation_form_submit($form, &$form_state) {
  $participant = $form['#participant'];
  $campaign = $form['#campaign'];

  // Créer une soumission.
  $submission = entity_create('submission', ['cid' => $campaign->cid]);
  $submission->save();

  foreach ($form_state['values']['question_groups'] as $qgid => $question_group_values) {
    // Stocker les points négatifs et positifs.
    $group_data = entity_create('group_data', [
      'positif' => $question_group_values['remarques']['positif'],
      'negatif' => $question_group_values['remarques']['negatif'],
      'qgid' => $qgid,
      'smid' => $submission->smid,
    ]);
    $group_data->save();

    // Stocker le nombre de points pour chaque question.
    foreach ($question_group_values['questions'] as $qid => $count) {
      $submitted_data = entity_create('submitted_data', [
        'count' => $count,
        'qid' => $qid,
        'smid' => $submission->smid,
      ]);
      $submitted_data->save();
    }
  }

  // Un participant ne doit pouvoir répondre qu'une fois.
  $participant->answered = TRUE;
  $participant->save();

  drupal_set_message(t("Merci d'avoir participé à cette évaluation."));
  $form_state['redirect'] = '<front>';
}

/**
 * Page callback: demo page for surveys.
 */
function ldlm_survey_survey_demo_page($survey) {
  $participant = entity_create('participant', [
    'mail' => 'demo@example.net',
    'surname' => 'Nonyme',
    'name' => 'A.',
  ]);
  $campaign = entity_create('campaign', [
    'title' => t("Campagne d'évaluation de démo"),
    'begin' => REQUEST_TIME - 5 * 86400,
    'end' => REQUEST_TIME + 7 * 86400,
    'status' => LDLM_SURVEY_STATUS_OPEN,
  ]);
  $participant->demo = [
    'campaign' => $campaign,
    'survey' => $survey,
  ];
  drupal_set_message(t('Ceci est une prévisualisation du questionnaire %title.', ['%title' => $survey->title]), 'warning');
  return drupal_get_form('ldlm_survey_evaluation_form', $participant);
}
