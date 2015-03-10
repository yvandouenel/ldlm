<?php
/**
 * @file
 * ldlm_page_classique.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ldlm_page_classique_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_en_tete|node|page|default';
  $field_group->group_name = 'group_en_tete';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
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
  $export['group_en_tete|node|page|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_titre_sous_titre|node|page|default';
  $field_group->group_name = 'group_titre_sous_titre';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_en_tete';
  $field_group->data = array(
    'label' => 'Titre-sous-titre',
    'weight' => '4',
    'children' => array(
      0 => 'field_sous_titre',
      1 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Titre-sous-titre',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-titre-sous-titre field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_titre_sous_titre|node|page|default'] = $field_group;

  return $export;
}
