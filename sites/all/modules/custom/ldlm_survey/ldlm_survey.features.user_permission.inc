<?php
/**
 * @file
 * ldlm_survey.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ldlm_survey_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer surveys'.
  $permissions['administer surveys'] = array(
    'name' => 'administer surveys',
    'roles' => array(
      'redacteur' => 'redacteur',
      'webmaster' => 'webmaster',
    ),
    'module' => 'ldlm_survey',
  );

  return $permissions;
}
