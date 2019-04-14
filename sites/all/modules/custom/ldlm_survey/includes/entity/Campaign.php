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
   * Return number of answers and total number of participants.
   */
  public function getAnsweredRatio() {
    return entity_get_controller($this->entityType)->getAnsweredRatio($this);
  }

  /**
   * Remarques soumises par les participants à cette campagne.
   */
  public function getRemarques() {
    return entity_get_controller($this->entityType)->getRemarques($this);
  }

  /**
   * Points par question pour cette campagne (ou le groupe de campagnes).
   */
  public function getRawResults($group = FALSE) {
    return entity_get_controller($this->entityType)->getRawResults($this, $group);
  }

  /**
   * Moyenne et écart type par question.
   */
  public function getResults($group = FALSE, $truncate = FALSE) {
    return entity_get_controller($this->entityType)->getResults($this, $group, $truncate);
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
