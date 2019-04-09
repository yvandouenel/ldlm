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

  $wr_participant = $participant->wrapper();
  $campaign = $wr_participant->cid->value();
  $survey = $wr_participant->cid->cgid->sid->value();
  $question_options = ldlm_survey_points();

  drupal_set_title($campaign->title);

  $form['#participant'] = $participant;
  $form['#campaign'] = $campaign;
  $form['#survey'] = $survey;
  $form['#tree'] = TRUE;

  foreach ($survey->getQuestionGroups() as $qgid => $question_group) {
    $form['question_groups'][$qgid] = [
      '#type' => 'fieldset',
      '#title' => check_plain($question_group->title),
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
      '#title' => t('Remarques, commentaires ou suggestions.'),
    ];
    $form['question_groups'][$qgid]['remarques']['positif'] = [
      '#type' => 'textarea',
      '#title' => t('Points positifs'),
      '#maxlength_js' => TRUE,
      '#maxlength' => 1500,
    ];
    $form['question_groups'][$qgid]['remarques']['negatif'] = [
      '#type' => 'textarea',
      '#title' => t('Points négatifs'),
      '#maxlength_js' => TRUE,
      '#maxlength' => 1500,
    ];
  }

  $form['actions'] = ['#type' => 'actions'];
  $form['actions']['submit'] = [
    '#type' => 'submit',
    '#value' => t("Envoyer"),
    '#name' => 'submit',
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
