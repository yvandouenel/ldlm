<?php
/**
 * @file
 * domainedo_editors.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function domainedo_editors_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer ckeditor'.
  $permissions['administer ckeditor'] = array(
    'name' => 'administer ckeditor',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ckeditor',
  );

  // Exported permission: 'customize ckeditor'.
  $permissions['customize ckeditor'] = array(
    'name' => 'customize ckeditor',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'ckeditor',
  );

  return $permissions;
}
