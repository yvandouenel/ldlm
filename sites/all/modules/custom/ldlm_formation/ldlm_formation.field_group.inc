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
  $field_group->identifier = 'group_en_tete|node|formation|default';
  $field_group->group_name = 'group_en_tete';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'formation';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Titre-sous-titre-image',
    'weight' => '0',
    'children' => array(
      0 => 'field_image_formation',
      1 => 'group_titre_sous_titre',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Titre-sous-titre-image',
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
  $export['group_en_tete|node|formation|default'] = $field_group;

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
    'weight' => '14',
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
    'weight' => '15',
    'children' => array(
      0 => 'field_objectif',
      1 => 'field_temoignages',
      2 => 'field_activites_parascolaires',
      3 => 'field_documentation',
      4 => 'field_demande_entretien',
      5 => 'field_preinscription_scolaire',
      6 => 'field_portes_ouvertes',
      7 => 'field_venir_lycee',
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
  $field_group->identifier = 'group_pre_inscription_pro|node|formation|default';
  $field_group->group_name = 'group_pre_inscription_pro';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'formation';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_pro';
  $field_group->data = array(
    'label' => 'Pré-inscription',
    'weight' => '5',
    'children' => array(
      0 => 'field_contact',
      1 => 'field_remplir_formulaire',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Pré-inscription',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-pre-inscription-pro field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_pre_inscription_pro|node|formation|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pro_bottom|node|formation|default';
  $field_group->group_name = 'group_pro_bottom';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'formation';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Pro bas',
    'weight' => '9',
    'children' => array(
      0 => 'field_sigles_abr',
      1 => 'field_diaporama',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => 'group-pro-bottom field-group-div',
        'id' => '',
      ),
    ),
  );
  $export['group_pro_bottom|node|formation|default'] = $field_group;

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
      1 => 'field_remplir_formulaire',
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

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pro|node|formation|default';
  $field_group->group_name = 'group_pro';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'formation';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'pro',
    'weight' => '10',
    'children' => array(
      0 => 'field_financement',
      1 => 'field_acces_centre',
      2 => 'group_pre_inscription_pro',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'pro',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-pro field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_pro|node|formation|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_scolaire_right|node|formation|default';
  $field_group->group_name = 'group_scolaire_right';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'formation';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Scolaire droite',
    'weight' => '13',
    'children' => array(
      0 => 'field_temoignages',
      1 => 'field_activites_parascolaires',
      2 => 'field_venir_lycee',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => 'group-scolaire-right field-group-div',
        'id' => '',
      ),
    ),
  );
  $export['group_scolaire_right|node|formation|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_scolaire|node|formation|default';
  $field_group->group_name = 'group_scolaire';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'formation';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Scolaire',
    'weight' => '8',
    'children' => array(
      0 => 'field_documentation',
      1 => 'field_demande_entretien',
      2 => 'field_preinscription_scolaire',
      3 => 'field_portes_ouvertes',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Scolaire',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-scolaire field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_scolaire|node|formation|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_titre_sous_titre|node|formation|default';
  $field_group->group_name = 'group_titre_sous_titre';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'formation';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_en_tete';
  $field_group->data = array(
    'label' => 'Titre-sous-titre',
    'weight' => '7',
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
  $export['group_titre_sous_titre|node|formation|default'] = $field_group;

  return $export;
}
