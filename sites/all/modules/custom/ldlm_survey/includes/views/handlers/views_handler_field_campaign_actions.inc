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
    $cid = $this->view->result[$this->view->row_index]->cid;
    $links = [
      l(t('exporter participants'), 'admin/content/survey/campaign/' . $cid . '/participants-csv'),
      l(t('exporter liens'), 'admin/content/survey/campaign/' . $cid . '/liens-csv'),
      l(t('delete'), 'admin/content/survey/campaign/' . $cid . '/delete'),
    ];
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
