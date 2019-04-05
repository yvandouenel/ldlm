<?php

/**
 * Campaign Group controller.
 */
class CampaignGroupController extends LdlmSurveyController {

  /**
   * Get all campaigns for this campaign group.
   */
  public function getCampaigns($campaign_group) {
    $campaigns = [];

    if (isset($campaign_group->cgid)) {
      $query = new EntityFieldQuery();
      $result = $query->entityCondition('entity_type', 'campaign')
        ->propertyCondition('cgid', $campaign_group->cgid)
        ->execute();

      if (!empty($result['campaign'])) {
        $cids = array_keys($result['campaign']);
        $campaigns = entity_load('campaign', $cids);
      }
    }

    return $campaigns;
  }

}
