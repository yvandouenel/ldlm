<?php

/**
 * Campaign controller.
 */
class CampaignController extends LdlmSurveyController {

  /**
   * {@inheritdoc}
   */
  public function delete($ids, DatabaseTransaction $transaction = NULL) {
    foreach ($this->load($ids) as $campaign) {
      // Supprimer les participants liés avant de supprimer la campagne.
      foreach ($campaign->getParticipants() as $participant) {
        $participant->delete();
      }

      // Si cette campagne est la dernière de son groupe, le supprimer.
      if ($campaign_group = campaign_group_load($campaign->cgid)) {
        if (count($campaign_group->getCampaigns()) == 1) {
          $campaign_group->delete();
        }
      }

      // Supprimer le fichier CSV des participants.
      $file = file_load($campaign->csv);
      file_usage_delete($file, 'ldlm_survey', 'campaign', $campaign->cid);
      file_delete($file);
    }

    parent::delete($ids, $transaction);
  }

  /**
   * Get all participants for this campaign.
   */
  public function getParticipants($campaign) {
    $participants = [];

    if (isset($campaign->cid)) {
      $query = new EntityFieldQuery();
      $result = $query->entityCondition('entity_type', 'participant')
        ->propertyCondition('cid', $campaign->cid)
        ->execute();

      if (!empty($result['participant'])) {
        $pids = array_keys($result['participant']);
        $participants = entity_load('participant', $pids);
      }
    }

    return $participants;
  }

}
