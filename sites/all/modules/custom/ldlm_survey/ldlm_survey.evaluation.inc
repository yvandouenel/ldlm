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

  drupal_set_title($campaign->title);

  $form['actions'] = ['#type' => 'actions'];
  $form['actions']['submit'] = [
    '#type' => 'submit',
    '#value' => t("Envoyer"),
    '#name' => 'submit',
  ];

  return $form;
}
