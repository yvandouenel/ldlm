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
    $answers = $total = 0;
    $campaign = campaign_load($cid);
    foreach ($campaign->getParticipants() as $participant) {
      $total++;
      if ($participant->answered) {
        $answers++;
      }
    }
    $ratio = $answers . '/' . $total;
    $percent = round(100 * $answers / $total) . ' %';
    return ['#markup' => $ratio . ' (' . $percent . ')'];
  }

}
