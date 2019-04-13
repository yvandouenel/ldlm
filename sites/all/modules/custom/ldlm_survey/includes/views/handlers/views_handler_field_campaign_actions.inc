<?php

/**
 * Liens d'administration des questionnaires.
 */
class views_handler_field_campaign_actions extends views_handler_field {

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
    $links = [];

    $links[] = l(t('view'), 'admin/content/survey/campaign/' . $campaign->cid);
    $links[] = l(t('participants'), 'admin/content/survey/campaign/' . $campaign->cid . '/participants');
    $links[] = l(t('remarques'), 'admin/content/survey/campaign/' . $campaign->cid . '/remarques');
    if ($campaign->status == LDLM_SURVEY_STATUS_SCHEDULED) {
      $links[] = l(t('modifier'), 'admin/content/survey/campaign/' . $campaign->cid . '/edit');
      $links[] = l(t('delete'), 'admin/content/survey/campaign/' . $cid . '/delete');
    }

    return [
      '#theme' => 'item_list',
      '#type' => 'ul',
      '#attributes' => [
        'class' => ['inline'],
      ],
      '#items' => $links,
    ];
  }

}
