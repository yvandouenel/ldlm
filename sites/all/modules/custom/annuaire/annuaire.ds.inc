<?php
/**
 * @file
 * annuaire.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function annuaire_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'user|user|default';
  $ds_fieldsetting->entity_type = 'user';
  $ds_fieldsetting->bundle = 'user';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_courriel_public' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Courriel',
        ),
      ),
    ),
  );
  $export['user|user|default'] = $ds_fieldsetting;

  return $export;
}
