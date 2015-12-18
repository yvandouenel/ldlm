<?php
/**
 * @file
 * ressource_documentaire.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ressource_documentaire_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_col_4|node|ressource_documentaire|default';
  $field_group->group_name = 'group_col_4';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ressource_documentaire';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_container_ds';
  $field_group->data = array(
    'label' => 'col-4',
    'weight' => '1',
    'children' => array(
      0 => 'field_rd_sous_titre',
      1 => 'field_liens_utiles',
      2 => 'field_type_de_document',
      3 => 'field_format_de_document',
      4 => 'field_image',
      5 => 'field_scald_file',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'col-4',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-col-4 field-group-div col-md-4',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_col_4|node|ressource_documentaire|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_col_8|node|ressource_documentaire|default';
  $field_group->group_name = 'group_col_8';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ressource_documentaire';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_container_ds';
  $field_group->data = array(
    'label' => 'Col-8',
    'weight' => '2',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Col-8',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-col-8 field-group-div col-md-8',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_col_8|node|ressource_documentaire|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_container_ds|node|ressource_documentaire|default';
  $field_group->group_name = 'group_container_ds';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ressource_documentaire';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Container-ds',
    'weight' => '0',
    'children' => array(
      0 => 'group_col_4',
      1 => 'group_col_8',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Container-ds',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-container-ds field-group-div container',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_container_ds|node|ressource_documentaire|default'] = $field_group;

  return $export;
}
