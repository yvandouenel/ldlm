<?php
/**
 * @file
 * news.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function news_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_autres-vnements:evenements
  $menu_links['main-menu_autres-vnements:evenements'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'evenements',
    'router_path' => 'evenements',
    'link_title' => 'Autres événements',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_autres-vnements:evenements',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -48,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Autres événements');


  return $menu_links;
}
