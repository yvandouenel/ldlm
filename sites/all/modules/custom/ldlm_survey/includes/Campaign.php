<?php

/**
 * Class for campaign entities.
 */
class Campaign extends Entity {

  /**
   * Get all participants for this campaign.
   */
  public function getParticipants() {
    return entity_get_controller($this->entityType)->getParticipants($this);
  }

}
