<?php
/**
 * @file
 * domainedo_media.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function domainedo_media_default_picture_mapping() {
  $export = array();

  $picture_mapping = new stdClass();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 1;
  $picture_mapping->machine_name = 'max';
  $picture_mapping->breakpoint_group = 'max';
  $picture_mapping->mapping = array(
    'breakpoints.theme.domainedo.mobile' => array(
      '1x' => 'maxbreakpoints_theme_domainedo_mobile_1x',
    ),
    'breakpoints.theme.domainedo.narrow' => array(
      '1x' => 'maxbreakpoints_theme_domainedo_narrow_1x',
    ),
    'breakpoints.theme.domainedo.wide' => array(
      '1x' => 'maxbreakpoints_theme_domainedo_wide_1x',
    ),
  );
  $export['max'] = $picture_mapping;

  $picture_mapping = new stdClass();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 1;
  $picture_mapping->machine_name = 'zoom';
  $picture_mapping->breakpoint_group = 'zoom';
  $picture_mapping->mapping = array(
    'breakpoints.theme.domainedo.mobile' => array(
      '1x' => 'zoombreakpoints_theme_domainedo_mobile_1x',
    ),
    'breakpoints.theme.domainedo.narrow' => array(
      '1x' => 'zoombreakpoints_theme_domainedo_narrow_1x',
    ),
    'breakpoints.theme.domainedo.wide' => array(
      '1x' => 'zoombreakpoints_theme_domainedo_wide_1x',
    ),
  );
  $export['zoom'] = $picture_mapping;

  $picture_mapping = new stdClass();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 1;
  $picture_mapping->machine_name = 'zoom_homepage';
  $picture_mapping->breakpoint_group = 'zoom_homepage';
  $picture_mapping->mapping = array(
    'breakpoints.theme.domainedo.mobile' => array(
      '1x' => 'zoombreakpoints_theme_domainedo_mobile_1x',
    ),
    'breakpoints.theme.domainedo.wide' => array(
      '1x' => 'zoombreakpoints_theme_domainedo_wide_1x',
    ),
    'breakpoints.theme.domainedo.narrow' => array(
      '1x' => 'zoombreakpoints_theme_domainedo_narrow_1x',
    ),
  );
  $export['zoom_homepage'] = $picture_mapping;

  return $export;
}
