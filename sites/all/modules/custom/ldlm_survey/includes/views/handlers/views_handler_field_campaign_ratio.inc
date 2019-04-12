<?php

/**
 * Liens d'administration des questionnaires.
 */
class views_handler_field_campaign_ratio extends views_handler_field {

  /**
   * {@inheritdoc}
   */
  public function query() {
    $this->add_additional_fields(['cid']);
  }

  /**
   * {@inheritdoc}
   */
  public function render($values) {
    $cid = $this->get_value($values, 'cid');
    $campaign = campaign_load($cid);
    return theme('answered_ratio', $campaign->getAnsweredRatio());
  }

}
