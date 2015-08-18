<?php
/**
 * @file
 * ldlm_formation.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function ldlm_formation_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|formation|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'formation';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h2',
        'class' => '',
        'exclude node title settings' => '0',
      ),
    ),
    'field_metiers' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Métiers',
          'lb-el' => 'h3',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_secteur_activite' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Secteurs d\'activité',
          'lb-el' => 'h3',
          'lb-cl' => 'h3-secteur-act',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_financement' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Financement',
          'lb-el' => 'h3',
          'lb-cl' => 'h3-training-right',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'div-scol-right first',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_acces_centre' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Accès au centre',
          'lb-el' => 'h3',
          'lb-cl' => 'h3-training-right',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'div-scol-right last',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_prerogatives' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Prérogatives',
          'lb-el' => 'h3',
          'lb-cl' => 'h3-formation',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_objectif' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Objectif',
          'lb-el' => 'h3',
          'lb-cl' => 'h3-formation',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_conditions_admission' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Conditions d\'admission',
          'lb-el' => 'h3',
          'lb-cl' => 'h3-formation',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_formation' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Formation',
          'lb-el' => 'h3',
          'lb-cl' => 'h3-formation',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_sanction' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Sanction',
          'lb-el' => 'h3',
          'lb-cl' => 'h3-formation',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_activites_parascolaires' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Activités parascolaires',
          'lb-el' => 'h3',
          'lb-cl' => 'h3-training-right',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'div-scol-right',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_venir_lycee' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Venir au Lycée',
          'lb-el' => 'h3',
          'lb-cl' => 'h3-training-right',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'div-scol-right',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_temoignages' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Témoignages',
          'lb-el' => 'h3',
          'lb-cl' => 'bg-rose-vent',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'div-scol-right',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_prochaines_dates' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Prochaines dates',
          'lb-el' => 'h3',
          'lb-cl' => 'h3-formation',
          'lb-col' => TRUE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'dates-debut-fin',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_debouches' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Débouchés',
          'lb-el' => 'h3',
          'lb-cl' => 'h3-formation',
        ),
      ),
    ),
  );
  $export['node|formation|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|formation|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'formation';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h4',
        'class' => 'h4-formation-home',
        'exclude node title settings' => '1',
        'ft' => array(),
      ),
    ),
  );
  $export['node|formation|teaser'] = $ds_fieldsetting;

  return $export;
}
