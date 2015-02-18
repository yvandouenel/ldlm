<section id="top_bar">
  <div class="center">
    <?php print render($page['top_bar']); ?>
  </div>
</section>
<section id="head_band">
  <div class="center">
    <h1><a href="."><img src="<?php print base_path() . path_to_theme(); ?>/images/logo-Paul-Bousquet.gif" alt="Paul Bousquet"></a></h1>
  </div>
</section>
<section id="main_content">
  <div class="center">
    <div class="black-header">
      <div class="ldlm-user-menu">
        <?php if ($logged_in): ?>
          <?php print render($page['user_menu']); ?>
        <?php else: ?>
          <ul>
            <li class="menu"><a href="<?php base_path(); ?>user/login">Log In</a></li>
          </ul>
        <?php endif; ?>
      </div>
    </div>
    <?php if ($title): ?>
        <h2 class="title" id="page-title">
          <?php print $title; ?>
        </h2>
      <?php endif; ?>
      <?php if ($action_links): ?>
        <ul class="action-links">
          <?php print render($action_links); ?>
        </ul>
      <?php endif; ?>
    <?php print render($page['content']); ?>
  </div>
</section>


