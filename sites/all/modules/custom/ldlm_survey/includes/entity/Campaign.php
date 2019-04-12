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

  /**
   * Delete all participants for this campaign.
   */
  public function deleteParticipants() {
    return entity_get_controller($this->entityType)->deleteParticipants($this);
  }

  /**
   * Delete participants CSV file.
   */
  public function deleteCsv() {
    return entity_get_controller($this->entityType)->deleteCsv($this);
  }

}
