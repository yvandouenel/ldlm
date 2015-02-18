<?php
/**
 * @file
 * domainedo_editors.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function domainedo_editors_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
