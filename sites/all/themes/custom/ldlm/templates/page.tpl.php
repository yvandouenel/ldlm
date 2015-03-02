<section id="top_bar">
  <div class="container">
    <?php print render($page['top_bar']); ?>
  </div>
</section>
<header id="head_band">
  <div class="container">
    <div class="grid-12 grid">
      <h1 id="paul_bousquet"><a href="<?php print $front_page; ?>"><img src="<?php print base_path() . path_to_theme(); ?>/images/logo-Paul-Bousquet.gif" alt="Paul Bousquet - Lycée de la mer - Pôle de formation maritime"></a></h1>
      <a id="link_ldlm" href="/vie-lyceenne">Lycée de la mer</a><a id="link_pdfm" href="/pole-formation-maritime">Pôle de formation maritime</a>
    </div>
    <div class="grid-6 grid">
      <nav id="main_menu">
        <?php print render($page['main_menu']); ?>
      </nav>
    </div>
    <div class="grid-6 grid">
      <nav id="secondary_menu">
        <?php print render($page['secondary_menu']); ?>
      </nav>
    </div>
  </div>
</header>
<section id="main_content">
  <div class="big-container">
    <?php print render($page['above_content']); ?>
  </div>
  <div class="container">
    <div class='grid-12 grid' class='clearfix'>
      <!-- Colonne de gauche -->
      <?php if ($page['sidebar_left']): ?>
        <div class='grid-3 first-col' id="sidebar-left"><?php print render($page['sidebar_left']) ?></div>
      <?php endif; ?>
      <!-- Colonne de droite -->   
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
    </div>
    <?php if ($page['home_col1']): ?>
      <div class='grid-6 grid'><?php print render($page['home_col1']) ?></div>
    <?php endif; ?>
    <?php if ($page['home_col2']): ?>
      <div class='grid-3 grid'><?php print render($page['home_col2']) ?></div>
    <?php endif; ?>
    <?php if ($page['home_col3']): ?>
      <div class='grid-3 grid'><?php print render($page['home_col3']) ?></div>
    <?php endif; ?> 
        
</div>
</section>
<footer id="main_footer">
   <div class="big-container container">
    <img id="img-bg-footer" src="<?php print base_path() . path_to_theme(); ?>/images/bg/bg_footer.jpg" alt="">
    <div id="footer-ldlm-pfm">
      <a id="link_ldlm" href="/vie-lyceenne">Lycée de la mer</a><span id="paul-bousquet-bas">Paul Bousquet</span><a id="link_pdfm" href="/pole-formation-maritime">Pôle de formation maritime</a>
    </div>
    <div id="cols-footer">
      <?php if ($page['footer_col1']): ?>
        <div class='grid-3 grid'><?php print render($page['footer_col1']) ?></div>
      <?php endif; ?>
      <?php if ($page['footer_col2']): ?>
        <div class='grid-3 grid'><?php print render($page['footer_col2']) ?></div>
      <?php endif; ?>
      <?php if ($page['footer_col3']): ?>
        <div class='grid-6 grid'><?php print render($page['footer_col3']) ?></div>
      <?php endif; ?> 
    </div>
  </div> 
</footer> 