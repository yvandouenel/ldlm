<?php
/**
 * @file
 * activites.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function activites_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_en_tete|node|activite|default';
  $field_group->group_name = 'group_en_tete';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'activite';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Titre-sous-tire-image',
    'weight' => '0',
    'children' => array(
      0 => 'field_image_en_tete',
      1 => 'group_titre_sous_titre',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Titre-sous-tire-image',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-en-tete field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_en_tete|node|activite|default'] = $field_group;

  return $export;
}
