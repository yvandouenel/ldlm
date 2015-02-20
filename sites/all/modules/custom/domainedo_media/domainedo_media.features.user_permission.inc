<?php
/**
 * @file
 * domainedo_media.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function domainedo_media_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer dnd'.
  $permissions['administer dnd'] = array(
    'name' => 'administer dnd',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'dnd',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer scald'.
  $permissions['administer scald'] = array(
    'name' => 'administer scald',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'scald',
  );

  // Exported permission: 'administer scald atoms'.
  $permissions['administer scald atoms'] = array(
    'name' => 'administer scald atoms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'scald',
  );

  // Exported permission: 'bypass atom access restrictions'.
  $permissions['bypass atom access restrictions'] = array(
    'name' => 'bypass atom access restrictions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'scald',
  );

  // Exported permission: 'create atom of any type'.
  $permissions['create atom of any type'] = array(
    'name' => 'create atom of any type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'scald',
  );

  // Exported permission: 'create atom of audio type'.
  $permissions['create atom of audio type'] = array(
    'name' => 'create atom of audio type',
    'roles' => array(),
    'module' => 'scald',
  );

  // Exported permission: 'create atom of file type'.
  $permissions['create atom of file type'] = array(
    'name' => 'create atom of file type',
    'roles' => array(),
    'module' => 'scald',
  );

  // Exported permission: 'create atom of gallery type'.
  $permissions['create atom of gallery type'] = array(
    'name' => 'create atom of gallery type',
    'roles' => array(),
    'module' => 'scald',
  );

  // Exported permission: 'create atom of twitter type'.
  $permissions['create atom of twitter type'] = array(
    'name' => 'create atom of twitter type',
    'roles' => array(),
    'module' => 'scald',
  );

  // Exported permission: 'delete any atom'.
  $permissions['delete any atom'] = array(
    'name' => 'delete any atom',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'scald',
  );

  // Exported permission: 'delete own atom'.
  $permissions['delete own atom'] = array(
    'name' => 'delete own atom',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'scald',
  );

  // Exported permission: 'edit any atom'.
  $permissions['edit any atom'] = array(
    'name' => 'edit any atom',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'scald',
  );

  // Exported permission: 'edit own atom'.
  $permissions['edit own atom'] = array(
    'name' => 'edit own atom',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'scald',
  );

  // Exported permission: 'fetch any atom'.
  $permissions['fetch any atom'] = array(
    'name' => 'fetch any atom',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'scald',
  );

  // Exported permission: 'fetch own atom'.
  $permissions['fetch own atom'] = array(
    'name' => 'fetch own atom',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'scald',
  );

  // Exported permission: 'restrict atom access'.
  $permissions['restrict atom access'] = array(
    'name' => 'restrict atom access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'scald',
  );

  // Exported permission: 'view any atom'.
  $permissions['view any atom'] = array(
    'name' => 'view any atom',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'redacteur' => 'redacteur',
      'webmaster' => 'webmaster',
    ),
    'module' => 'scald',
  );

  // Exported permission: 'view own atom'.
  $permissions['view own atom'] = array(
    'name' => 'view own atom',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'scald',
  );

  return $permissions;
}
