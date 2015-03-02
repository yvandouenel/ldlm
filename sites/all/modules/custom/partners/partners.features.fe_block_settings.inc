<?php
/**
 * @file
 * partners.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function partners_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-partenaires-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'partenaires-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'ldlm' => array(
        'region' => 'footer_col3',
        'status' => 1,
        'theme' => 'ldlm',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['views-partenaires-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'partenaires-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'ldlm' => array(
        'region' => 'footer_col3',
        'status' => 1,
        'theme' => 'ldlm',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
