<?php
/**
 * @file
 * ldlm_page_classique.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ldlm_page_classique_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ldlm_page_classique_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Page classique'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
