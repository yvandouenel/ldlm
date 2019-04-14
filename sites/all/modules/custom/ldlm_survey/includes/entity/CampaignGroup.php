<?php

/**
 * Class for campaign group entities.
 */
class CampaignGroup extends Entity {

  /**
   * Get all campaigns for this campaign group.
   */
  public function getCampaigns($raw = FALSE) {
    return entity_get_controller($this->entityType)->getCampaigns($this, $raw);
  }

}
