<section id="top_bar">
  <div class="container">
    <?php print render($page['top_bar']); ?>
  </div>
</section>
<section id="head_band">
  <div class="container">
    <h1 id="paul_bousquet"><a href="<?php print $front_page; ?>"><img src="<?php print base_path() . path_to_theme(); ?>/images/logo-Paul-Bousquet.gif" alt="Paul Bousquet"></a></h1>
    <a id="link_ldlm" href="/vie-lyceenne">Lycée de la mer</a><a id="link_pdfm" href="/pole-formation-maritime">Pôle de formation maritime</a>
    <nav id="main_menu">
      <?php print render($page['main_menu']); ?>
    </nav>
  </div>
</section>
<section id="main_content">
  <div class="container">
    <?php if ($messages): ?>
    <div id="messages"><div class="section clearfix">
      <?php print $messages; ?>
    </div></div> <!-- /.section, /#messages -->
    <?php endif; ?>
  <?php print render($title_suffix); ?>
    <?php if ($title): ?>
        <h2 class="title" id="page-title">
          <?php print $title; ?>
        </h2>
      <?php endif; ?>
      <?php if ($tabs): ?>
        <div class="tabs">
          <?php print render($tabs); ?>
        </div>
      <?php endif; ?>
      <?php print render($page['help']); ?>
      <?php if ($action_links): ?>
        <ul class="action-links">
          <?php print render($action_links); ?>
        </ul>
      <?php endif; ?>
   
      <?php print render($page['content']); ?>
      <?php if ($page['home_col1']): ?>
        <div class='grid-6' class='clearfix'><?php print render($page['home_col1']) ?></div>
      <?php endif; ?>
        <div class='grid-3' class='clearfix'>1<?php print render($page['home_col2']) ?></div>
        <div class='grid-3' class='clearfix'>2<?php print render($page['home_col3']) ?></div>

</div>
</section>