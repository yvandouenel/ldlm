<?php
/**
 * @file
 * ldlm_formation.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ldlm_formation_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_infos_pro|node|formation|form';
  $field_group->group_name = 'group_infos_pro';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'formation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'infos pro',
    'weight' => '11',
    'children' => array(
      0 => 'field_financement',
      1 => 'field_acces_centre',
      2 => 'field_prerogatives',
      3 => 'field_sigles_abr',
      4 => 'group_pro_inscription',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'infos pro',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-infos-pro field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_infos_pro|node|formation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_infos_scolaire|node|formation|form';
  $field_group->group_name = 'group_infos_scolaire';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'formation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'infos scolaire',
    'weight' => '12',
    'children' => array(
      0 => 'field_objectif',
      1 => 'field_temoignages',
      2 => 'field_activites_parascolaires',
      3 => 'field_preinscription_scolaire',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'infos scolaire',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-infos-scolaire field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_infos_scolaire|node|formation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pro_inscription|node|formation|form';
  $field_group->group_name = 'group_pro_inscription';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'formation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_infos_pro';
  $field_group->data = array(
    'label' => 'Pré-inscription',
    'weight' => '47',
    'children' => array(
      0 => 'field_contact',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Pré-inscription',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-pro-inscription field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_pro_inscription|node|formation|form'] = $field_group;

  return $export;
}
