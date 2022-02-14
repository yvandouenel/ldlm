<?php

/**
 * Add a google font
 */
function ldlm_preprocess_html(&$variables) {
  drupal_add_css('https://fonts.googleapis.com/css?family=Open+Sans',array('type' => 'external'));

  /* Ajoute une class à body si c'est une page pro */
  $node = menu_get_object();
  if ($node && isset($node->field_pro)) {
    if(isset($node->field_pro['und'][0]['value']) && $node->field_pro['und'][0]['value']) $variables['classes_array'][] = 'pro';
    else  $variables['classes_array'][] = 'no-pro';
  }

}

function ldlm_preprocess_image(&$variables) {
  foreach (array('width', 'height') as $key) {

   unset($variables[$key]);
   unset($variables[$key]);
 }
}
