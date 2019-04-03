<?php

/**
 * @file
 * Views hooks.
 */

/**
 * Implements hook_views_data_alter().
 */
function ldlm_survey_views_data_alter(&$data) {
  // Field handlers.
  $data['views']['field_survey_actions'] = [
    'title' => t("Liens d'administration des questionnaires"),
    'help' => t("Liens permettant diverses opérations sur les questionnaires, comme l'édition et la suppression"),
    'field' => [
      'handler' => 'views_handler_field_survey_actions',
    ],
  ];
}
