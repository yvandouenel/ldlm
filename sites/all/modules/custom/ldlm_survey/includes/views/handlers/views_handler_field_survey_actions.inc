<?php

/**
 * Liens d'administration des questionnaires.
 */
class views_handler_field_survey_actions extends views_handler_field {

  /**
   * {@inheritdoc}
   */
  public function query() {
    $this->add_additional_fields(['sid']);
  }

  /**
   * {@inheritdoc}
   */
  public function render($values) {
    $sid = $this->get_value($values, 'sid');
    $survey = survey_load($sid);
    $campaign_groups = $survey->getCampaignGroups();

    if (!$campaign_groups) {
      $links[] = l(t('edit'), 'admin/content/survey/survey/' . $sid . '/edit');
    }
    $links[] = l(t('clone'), 'admin/content/survey/survey/' . $sid . '/clone');
    if (!$campaign_groups) {
      $links[] = l(t('delete'), 'admin/content/survey/survey/' . $sid . '/delete');
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
