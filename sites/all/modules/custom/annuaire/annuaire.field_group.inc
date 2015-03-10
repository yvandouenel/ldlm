<?php
/**
 * @file
 * annuaire.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function annuaire_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_apres_click|user|user|default';
  $field_group->group_name = 'group_apres_click';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'apres click',
    'weight' => '1',
    'children' => array(
      0 => 'field_tel',
      1 => 'field_courriel_public',
      2 => 'field_image_publique',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'apres click',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-apres-click field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_apres_click|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cliquable|user|user|default';
  $field_group->group_name = 'group_cliquable';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'cliquable',
    'weight' => '0',
    'children' => array(
      0 => 'field_nom',
      1 => 'field_prenom',
      2 => 'field_titre',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'cliquable',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-cliquable field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_cliquable|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_infos_privees|user|user|form';
  $field_group->group_name = 'group_infos_privees';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Infos privées',
    'weight' => '0',
    'children' => array(
      0 => 'ckeditor',
      1 => 'metatags',
      2 => 'redirect',
      3 => 'account',
      4 => 'timezone',
      5 => 'picture',
      6 => 'overlay_control',
      7 => 'locale',
      8 => 'group_infos_public',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Infos privées',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-infos-privees field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_infos_privees|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_infos_public|user|user|form';
  $field_group->group_name = 'group_infos_public';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_infos_privees';
  $field_group->data = array(
    'label' => 'Infos pour le public',
    'weight' => '8',
    'children' => array(
      0 => 'field_nom',
      1 => 'field_prenom',
      2 => 'field_tel',
      3 => 'field_titre',
      4 => 'field_courriel_public',
      5 => 'field_school_member',
      6 => 'field_image_publique',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => 'group-infos-public field-group-div',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_infos_public|user|user|form'] = $field_group;

  return $export;
}
