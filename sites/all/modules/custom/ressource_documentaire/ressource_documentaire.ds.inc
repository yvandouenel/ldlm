<?php
/**
 * @file
 * ressource_documentaire.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function ressource_documentaire_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|ressource_documentaire|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'ressource_documentaire';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_container_ds',
        1 => 'field_scald_file',
        2 => 'group_col_4',
        3 => 'field_image',
        4 => 'field_rd_sous_titre',
        5 => 'group_col_8',
        6 => 'field_type_de_document',
        7 => 'field_format_de_document',
        8 => 'field_liens_utiles',
        9 => 'body',
      ),
    ),
    'fields' => array(
      'group_container_ds' => 'ds_content',
      'field_scald_file' => 'ds_content',
      'group_col_4' => 'ds_content',
      'field_image' => 'ds_content',
      'field_rd_sous_titre' => 'ds_content',
      'group_col_8' => 'ds_content',
      'field_type_de_document' => 'ds_content',
      'field_format_de_document' => 'ds_content',
      'field_liens_utiles' => 'ds_content',
      'body' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|ressource_documentaire|default'] = $ds_layout;

  return $export;
}
