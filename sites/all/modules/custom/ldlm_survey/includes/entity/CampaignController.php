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
      $campaign->deleteParticipants();

      // Si cette campagne est la dernière de son groupe, le supprimer.
      if ($campaign_group = campaign_group_load($campaign->cgid)) {
        if (count($campaign_group->getCampaigns()) == 1) {
          $campaign_group->delete();
        }
      }

      // Supprimer le fichier CSV des participants.
      $campaign->deleteCsv();
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
        ->propertyOrderBy('surname')
        ->execute();

      if (!empty($result['participant'])) {
        $pids = array_keys($result['participant']);
        $participants = entity_load('participant', $pids);
      }
    }

    return $participants;
  }

  /**
   * Return number of answers and total number of participants.
   */
  public function getAnsweredRatio($campaign) {
    $answers = $total = 0;

    foreach ($campaign->getParticipants() as $participant) {
      $total++;
      if ($participant->answered) {
        $answers++;
      }
    }

    return [
      'answers' => $answers,
      'total' => $total,
    ];
  }

  /**
   * Remarques soumises par les participants à cette campagne.
   */
  public function getRemarques($campaign) {
    $query = db_select('ldlm_group_data', 'gd');
    $query->join('ldlm_submission', 'sm', 'sm.smid = gd.smid');
    $result = $query->fields('gd', ['qgid', 'positif', 'negatif'])
      ->condition('sm.cid', $campaign->cid)
      ->orderBy('gd.created')
      ->execute();
    $remarques = [];
    while ($record = $result->fetchAssoc()) {
      if (empty($record['positif']) && empty($record['negatif'])) {
        continue;
      }
      $remarques[$record['qgid']][] = [
        'positif' => $record['positif'],
        'negatif' => $record['negatif'],
      ];
    }

    return $remarques;
  }

  /**
   * Points par question pour cette campagne (ou le groupe de campagnes).
   */
  public function getRawResults($campaign, $group, $truncate) {
    if ($group) {
      $campaign_group = campaign_group_load($campaign->cgid);
      $cids = $campaign_group->getCampaigns(TRUE);
    }
    else {
      $cids = $campaign->cid;
    }

    $query = db_select('ldlm_submitted_data', 'smd');
    $query->join('ldlm_submission', 'sm', 'sm.smid = smd.smid');
    $query->join('ldlm_question', 'q', 'q.qid = smd.qid');
    $query->join('ldlm_question_group', 'qg', 'qg.qgid = q.qgid');
    $result = $query->fields('smd', ['qid', 'count', 'smid'])
      ->fields('q', ['qgid'])
      ->fields('qg', ['sid'])
      ->condition('sm.cid', $cids)
      ->orderBy('smd.created')
      ->execute();
    $results = [];
    while ($record = $result->fetchAssoc()) {
      $results['survey'][$record['sid']][$record['smid']][] = $record['count'];
      if (!$truncate) {
        $results['question_group'][$record['qgid']][$record['smid']][] = $record['count'];
        $results['question'][$record['qid']][$record['smid']][] = $record['count'];
      }
    }

    return $results;
  }

  /**
   * Moyenne et écart type par question.
   */
  public function getResults($campaign, $group, $truncate) {
    $results = $campaign->getRawResults($group, $truncate);

    if (!$results) {
      return [];
    }

    foreach ($results as $entity_type => &$entities) {
      foreach ($entities as $entity_id => &$submissions) {
        $averages = [];
        foreach ($submissions as $smid => $submission) {
          $averages[] = array_sum($submission) / count($submission);
        }
        $count = count($averages);
        $avg = array_sum($averages) / $count;
        $sq_averages = array_map(function ($n) {
          return $n * $n;
        }, $averages);
        $stddev = sqrt(array_sum($sq_averages) / $count - $avg * $avg);
        $submissions = [
          'avg' => [
            'value' => $avg,
            'quality' => $this->assessment($avg, 'avg'),
          ],
          'stddev' => [
            'value' => $stddev,
            'quality' => $this->assessment($stddev, 'stddev'),
          ],
        ];
      }
    }

    return $results;
  }

  /**
   * Appréciation qualitative du résultat.
   *
   * On divise en trois parties les intervalles dans lesquels les grandeurs
   * prennent leurs valeurs.
   */
  protected function assessment($value, $type) {
    // Éviter les problèmes liés à l'arrondi, sans toutefois modifier les
    // valeurs brutes pour l'instant.
    $value = round($value, 1);
    switch ($type) {
      // Les points varient de 1 à 4, la moyenne aussi.
      case 'avg':
        if ($value <= 2) {
          return 'bad';
        }
        elseif ($value >= 3) {
          return 'good';
        }
        break;

      // L'écart type varie entre 0 et 1,5.
      case 'stddev':
        if ($value >= 1) {
          return 'bad';
        }
        elseif ($value <= 0.5) {
          return 'good';
        }
        break;
    }
    return 'normal';
  }

  /**
   * Delete all participants for this campaign.
   */
  public function deleteParticipants($campaign) {
    foreach ($campaign->getParticipants() as $participant) {
      $participant->delete();
    }
  }

  /**
   * Delete participants CSV file.
   */
  public function deleteCsv($campaign) {
    $file = file_load($campaign->csv);
    file_usage_delete($file, 'ldlm_survey', 'campaign', $campaign->cid);
    file_delete($file);
  }

}
