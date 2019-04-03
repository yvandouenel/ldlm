<?php

/**
 * @file
 * Questionnaires.
 */

/**
 * Formulaire d'édition d'un questionnaire.
 */
function ldlm_survey_survey_form($form, &$form_state, $survey = NULL) {
  $form = [];

  if (!isset($form_state['storage']['survey'])) {
    if (!$survey) {
      $survey = entity_create('survey', []);
    }
    $form_state['storage']['survey'] = $survey;
  }
  if (!isset($form_state['storage']['question_groups'])) {
    $form_state['storage']['question_groups'] = array_values($form_state['storage']['survey']->getQuestionGroups());
  }
  if (!isset($form_state['storage']['question_groups_total'])) {
    $form_state['storage']['question_groups_total'] = count($form_state['storage']['question_groups']) + 1;
  }
  elseif (isset($form_state['triggering_element']['#name']) && $form_state['triggering_element']['#name'] == 'add_question_group') {
    $form_state['storage']['question_groups_total']++;
  }

  $form['#tree'] = TRUE;
  $form['title'] = [
    '#type' => 'textfield',
    '#title' => t('Titre'),
    '#description' => t("Titre du formulaire, utilisé pour l'administration."),
    '#size' => 60,
    '#maxlength' => 128,
    '#default_value' => isset($form_state['storage']['survey']->title) ? $form_state['storage']['survey']->title : '',
  ];
  $form['question_groups'] = [
    '#type' => 'container',
    '#prefix' => '<div id="question-groups">',
    '#suffix' => '</div>',
  ];
  for ($i = 0; $i < $form_state['storage']['question_groups_total']; $i++) {
    if (isset($form_state['storage']['question_groups'][$i])) {
      $question_group = $form_state['storage']['question_groups'][$i];
      $form_state['storage']['questions'][$i] = array_values($question_group->getQuestions());
      if (!isset($form_state['storage']['questions_total'][$i])) {
        $form_state['storage']['questions_total'][$i] = count($form_state['storage']['questions'][$i]) + 1;
      }
    }
    else {
      $question_group = NULL;
      if (!isset($form_state['storage']['questions_total'][$i])) {
        $form_state['storage']['questions_total'][$i] = 1;
      }
    }
    if (isset($form_state['triggering_element']['#question_group']) && $form_state['triggering_element']['#question_group'] == $i) {
      $form_state['storage']['questions_total'][$i]++;
    }
    $form['question_groups'][$i]['question_group'] = [
      '#type' => 'fieldset',
      '#title' => t('Groupe de question'),
      '#collapsed' => FALSE,
      '#collapsible' => FALSE,
    ];
    $form['question_groups'][$i]['question_group']['title'] = [
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#description' => t("Titre du groupe de questions. Laisser vide pour supprimer entièrement ce groupe et les questions qu'il contient."),
      '#size' => 60,
      '#maxlength' => 128,
      '#default_value' => isset($question_group->title) ? $question_group->title : '',
    ];
    $form['question_groups'][$i]['question_group']['questions'] = [
      '#type' => 'container',
      '#prefix' => '<div id="questions-' . $i . '">',
      '#suffix' => '</div>',
    ];
    for ($j = 0; $j < $form_state['storage']['questions_total'][$i]; $j++) {
      $question = isset($form_state['storage']['questions'][$i][$j]) ? $form_state['storage']['questions'][$i][$j] : NULL;
      $form['question_groups'][$i]['question_group']['questions'][$j]['title'] = [
        '#type' => 'textfield',
        '#title' => t('Question'),
        '#description' => t('Libellé de la question.'),
        '#size' => 60,
        '#maxlength' => 128,
        '#default_value' => isset($question->label) ? $question->label : '',
      ];
    }
    $form['question_groups'][$i]['question_group']['add_question'] = [
      '#type' => 'button',
      '#value' => t('Ajouter une question'),
      '#name' => 'add_question_' . $i,
      '#question_group' => $i,
      '#ajax' => [
        'callback' => 'ldlm_survey_add_question',
        'wrapper' => 'questions-' . $i,
      ],
    ];
  }
  $form['add_question_group'] = [
    '#type' => 'button',
    '#value' => t('Ajouter un groupe de questions'),
    '#name' => 'add_question_group',
    '#ajax' => [
      'callback' => 'ldlm_survey_add_question_group',
      'wrapper' => 'question-groups',
    ],
  ];
  $form['actions'] = ['#type' => 'actions'];
  $form['actions']['submit'] = [
    '#type' => 'submit',
    '#value' => t('Save'),
    '#name' => 'submit',
  ];

  return $form;
}

/**
 * Ajouter un élément de formulaire pour un groupe de questions.
 */
function ldlm_survey_add_question_group($form, $form_state) {
  return $form['question_groups'];
}

/**
 * Ajouter un élément de formulaire pour une question.
 */
function ldlm_survey_add_question($form, $form_state) {
  $question_group = $form_state['triggering_element']['#question_group'];
  return $form['question_groups'][$question_group]['question_group']['questions'];
}

/**
 * Formulaire d'édition d'un questionnaire (submit).
 */
function ldlm_survey_survey_form_submit($form, &$form_state) {
  // Enquête de satisfaction.
  $survey = $form_state['storage']['survey'];
  $survey->title = $form_state['values']['title'];
  $survey->save();

  // Blocs de questions.
  foreach ($form_state['values']['question_groups'] as $i => $question_group_values) {
    $deleted = FALSE;
    if (isset($form_state['storage']['question_groups'][$i])) {
      $question_group = $form_state['storage']['question_groups'][$i];
      if (empty($question_group_values['question_group']['title'])) {
        $question_group->delete();
        $deleted = TRUE;
      }
      else {
        $question_group->title = $question_group_values['question_group']['title'];
        $question_group->save();
      }
    }
    elseif (!empty($question_group_values['question_group']['title'])) {
      $question_group = entity_create('question_group', [
        'sid' => $survey->sid,
        'title' => $question_group_values['question_group']['title'],
      ]);
      $question_group->save();
    }
    if (!$deleted) {
      foreach ($question_group_values['question_group']['questions'] as $j => $question_values) {
        if (isset($form_state['storage']['questions'][$i][$j])) {
          $question = $form_state['storage']['questions'][$i][$j];
          if (empty($question_values['title'])) {
            $question->delete();
          }
          else {
            $question->label = $question_values['title'];
            $question->save();
          }
        }
        elseif (!empty($question_values['title'])) {
          $question = entity_create('question', [
            'qgid' => $question_group->qgid,
            'label' => $question_values['title'],
          ]);
          $question->save();
        }
      }
    }
  }

  $form_state['redirect'] = 'admin/content/survey/survey/' . $survey->sid . '/edit';
}
