/**
 * ACM Algorithm Notes - Navigation Enhancement
 * Features: back button, sidebar TOC, back-to-top, copy button, search, theme toggle, cross-links
 */
(function () {
  'use strict';

  const BASE = getBasePath();

  // ===== 1. Back Button (top-left) =====
  const backBtn = document.createElement('a');
  backBtn.className = 'nav-back-btn';
  backBtn.href = BASE + 'index.html';
  backBtn.innerHTML = '<svg width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2.5" stroke-linecap="round" stroke-linejoin="round"><polyline points="15 18 9 12 15 6"/></svg> 返回目录';
  document.body.appendChild(backBtn);

  // ===== 2. Sidebar TOC (right side, collapsible) =====
  const headings = document.querySelectorAll('.section h2, .section h3, .section-title');
  if (headings.length > 1) {
    const sidebar = document.createElement('nav');
    sidebar.className = 'sidebar-toc';
    sidebar.innerHTML = `
      <div class="sidebar-toc-title">目录</div>
      <ul class="sidebar-toc-list"></ul>
    `;
    const list = sidebar.querySelector('.sidebar-toc-list');

    headings.forEach((h, i) => {
      if (!h.id) h.id = 'heading-' + i;
      const li = document.createElement('li');
      li.className = 'sidebar-toc-item' + (h.tagName === 'H3' ? ' sidebar-toc-sub' : '');
      const a = document.createElement('a');
      a.href = '#' + h.id;
      a.textContent = h.textContent;
      a.className = 'sidebar-toc-link';
      li.appendChild(a);
      list.appendChild(li);
    });

    document.body.appendChild(sidebar);

    // Toggle button — fixed at right edge, separate from sidebar
    const toggle = document.createElement('button');
    toggle.className = 'sidebar-toggle';
    toggle.title = '收起/展开目录';
    toggle.innerHTML = '<svg width="12" height="12" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2.5" stroke-linecap="round" stroke-linejoin="round"><polyline points="9 18 15 12 9 6"/></svg>';
    document.body.appendChild(toggle);

    const sidebarStateKey = 'algo-notes-sidebar-collapsed';
    const saved = localStorage.getItem(sidebarStateKey);
    const startCollapsed = saved === null ? true : saved === 'true';
    if (startCollapsed) sidebar.classList.add('collapsed');

    toggle.addEventListener('click', (e) => {
      e.stopPropagation();
      sidebar.classList.toggle('collapsed');
      localStorage.setItem(sidebarStateKey, sidebar.classList.contains('collapsed'));
    });

    // Click outside sidebar (but not on toggle) to collapse
    document.addEventListener('click', (e) => {
      if (!sidebar.classList.contains('collapsed') && !sidebar.contains(e.target) && !toggle.contains(e.target)) {
        sidebar.classList.add('collapsed');
        localStorage.setItem(sidebarStateKey, 'true');
      }
    });

    const links = sidebar.querySelectorAll('.sidebar-toc-link');
    const offsetMap = Array.from(headings);

    function updateActive() {
      const scrollY = window.scrollY + 120;
      let activeIdx = 0;
      for (let i = 0; i < offsetMap.length; i++) {
        if (offsetMap[i].offsetTop <= scrollY) activeIdx = i;
      }
      links.forEach((l, i) => l.classList.toggle('active', i === activeIdx));
    }

    window.addEventListener('scroll', updateActive, { passive: true });
    updateActive();

    links.forEach(link => {
      link.addEventListener('click', e => {
        e.preventDefault();
        const target = document.querySelector(link.getAttribute('href'));
        if (target) window.scrollTo({ top: target.offsetTop - 20, behavior: 'smooth' });
        // Auto-collapse on link click (mobile-friendlier)
        sidebar.classList.add('collapsed');
        localStorage.setItem(sidebarStateKey, 'true');
      });
    });
  }

  // ===== 3. Back to Top Button (bottom-right) =====
  const topBtn = document.createElement('button');
  topBtn.className = 'nav-top-btn';
  topBtn.innerHTML = '<svg width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2.5" stroke-linecap="round" stroke-linejoin="round"><polyline points="18 15 12 9 6 15"/></svg>';
  topBtn.title = '回到顶部';
  document.body.appendChild(topBtn);

  function toggleTopBtn() {
    topBtn.classList.toggle('show', window.scrollY > 400);
  }
  window.addEventListener('scroll', toggleTopBtn, { passive: true });
  toggleTopBtn();
  topBtn.addEventListener('click', () => window.scrollTo({ top: 0, behavior: 'smooth' }));

  // ===== 4. Copy Button for Code Blocks =====
  document.querySelectorAll('pre').forEach(pre => {
    if (pre.querySelector('.code-copy-btn')) return;
    const btn = document.createElement('button');
    btn.className = 'code-copy-btn';
    btn.innerHTML = copyIcon();
    btn.title = '复制代码';
    btn.addEventListener('click', () => {
      const code = pre.querySelector('code');
      const text = code ? code.textContent : pre.textContent;
      const done = () => {
        btn.classList.add('copied');
        btn.innerHTML = checkIcon();
        setTimeout(() => { btn.classList.remove('copied'); btn.innerHTML = copyIcon(); }, 1500);
      };
      navigator.clipboard.writeText(text).then(done).catch(() => {
        const ta = document.createElement('textarea');
        ta.value = text; ta.style.cssText = 'position:fixed;opacity:0';
        document.body.appendChild(ta); ta.select(); document.execCommand('copy');
        document.body.removeChild(ta); done();
      });
    });
    pre.appendChild(btn);
  });

  // ===== 5. Global Search (top-right) =====
  const searchWrap = document.createElement('div');
  searchWrap.className = 'search-wrap';
  searchWrap.innerHTML = `
    <div class="search-box">
      <svg class="search-icon" width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><circle cx="11" cy="11" r="8"/><line x1="21" y1="21" x2="16.65" y2="16.65"/></svg>
      <input class="search-input" type="text" placeholder="搜索算法 (Ctrl+K)" autocomplete="off">
      <div class="search-results"></div>
    </div>
  `;
  document.body.appendChild(searchWrap);

  const searchInput = searchWrap.querySelector('.search-input');
  const searchResults = searchWrap.querySelector('.search-results');
  // search-index.js is already loaded via <script> tag in HTML
  const searchIndex = typeof SEARCH_INDEX !== 'undefined' ? SEARCH_INDEX : null;

  function loadSearchIndex() {
    // no-op, index is already available
  }

  function doSearch(query) {
    if (!searchIndex || !query.trim()) { searchResults.innerHTML = ''; searchResults.classList.remove('show'); return; }
    const q = query.toLowerCase();
    const matched = searchIndex.filter(item =>
      item.title.toLowerCase().includes(q) ||
      item.keywords.toLowerCase().includes(q) ||
      item.cat.toLowerCase().includes(q)
    ).slice(0, 10);

    if (!matched.length) {
      searchResults.innerHTML = '<div class="search-empty">未找到相关内容</div>';
    } else {
      searchResults.innerHTML = matched.map(item => {
        const href = BASE + item.url;
        return `<a class="search-result-item" href="${href}">
          <span class="search-result-cat">${item.cat}</span>
          <span class="search-result-title">${item.title}</span>
        </a>`;
      }).join('');
    }
    searchResults.classList.add('show');
  }

  searchInput.addEventListener('input', () => doSearch(searchInput.value));

  // Ctrl+K shortcut
  document.addEventListener('keydown', e => {
    if ((e.ctrlKey || e.metaKey) && e.key === 'k') {
      e.preventDefault();
      searchInput.focus();
      loadSearchIndex();
    }
    if (e.key === 'Escape') {
      searchInput.blur();
      searchResults.classList.remove('show');
    }
  });

  // Close on outside click
  document.addEventListener('click', e => {
    if (!searchWrap.contains(e.target)) searchResults.classList.remove('show');
  });

  // ===== 6. Theme Toggle =====
  const themeBtn = document.createElement('button');
  themeBtn.className = 'theme-toggle-btn';
  themeBtn.title = '切换亮色/暗色主题';
  const savedTheme = localStorage.getItem('algo-notes-theme') || 'dark';
  if (savedTheme === 'light') document.documentElement.classList.add('light-theme');
  updateThemeIcon();

  function updateThemeIcon() {
    const isLight = document.documentElement.classList.contains('light-theme');
    themeBtn.innerHTML = isLight
      ? '<svg width="18" height="18" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><path d="M21 12.79A9 9 0 1 1 11.21 3 7 7 0 0 0 21 12.79z"/></svg>'
      : '<svg width="18" height="18" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><circle cx="12" cy="12" r="5"/><line x1="12" y1="1" x2="12" y2="3"/><line x1="12" y1="21" x2="12" y2="23"/><line x1="4.22" y1="4.22" x2="5.64" y2="5.64"/><line x1="18.36" y1="18.36" x2="19.78" y2="19.78"/><line x1="1" y1="12" x2="3" y2="12"/><line x1="21" y1="12" x2="23" y2="12"/><line x1="4.22" y1="19.78" x2="5.64" y2="18.36"/><line x1="18.36" y1="5.64" x2="19.78" y2="4.22"/></svg>';
  }

  themeBtn.addEventListener('click', () => {
    document.documentElement.classList.toggle('light-theme');
    const theme = document.documentElement.classList.contains('light-theme') ? 'light' : 'dark';
    localStorage.setItem('algo-notes-theme', theme);
    updateThemeIcon();
  });
  document.body.appendChild(themeBtn);

  // ===== 7. Cross-links (related algorithms) =====
  const RELATIONS = {
    'binary-search.html':   ['prefix-sum.html', 'greedy.html', 'stl.html'],
    'prefix-sum.html':      ['binary-search.html', 'bit-fenwick.html', 'monotone-queue.html'],
    'greedy.html':          ['binary-search.html', 'interval-dp.html', 'mst.html'],
    'divide-conquer.html':  ['segment-tree.html', 'linear-dp.html', 'quick-sort'],
    'bit.html':             ['bitmask-dp.html', 'bit-fenwick.html', 'trie.html'],
    'stl.html':             ['binary-search.html', 'priority-queue', 'monotone-queue.html'],
    'dfs.html':             ['bfs.html', 'backtracking.html', 'scc.html'],
    'bfs.html':             ['dfs.html', 'shortest-path.html', 'topo-sort.html'],
    'idastar.html':         ['dfs.html', 'bfs.html', 'backtracking.html'],
    'backtracking.html':    ['dfs.html', 'bitmask-dp.html', 'bit.html'],
    'linear-dp.html':       ['knapsack.html', 'greedy.html', 'bit-fenwick.html'],
    'knapsack.html':        ['linear-dp.html', 'greedy.html', 'bitmask-dp.html'],
    'interval-dp.html':     ['tree-dp.html', 'knapsack.html', 'dp-opt.html'],
    'tree-dp.html':         ['interval-dp.html', 'lca.html', 'union-find.html'],
    'digit-dp.html':        ['bitmask-dp.html', 'linear-dp.html', 'backtracking.html'],
    'bitmask-dp.html':      ['bit.html', 'digit-dp.html', 'knapsack.html'],
    'dp-opt.html':          ['monotone-queue.html', 'interval-dp.html', 'linear-dp.html'],
    'graph-rep.html':       ['shortest-path.html', 'mst.html', 'dfs.html'],
    'shortest-path.html':   ['mst.html', 'topo-sort.html', 'network-flow.html'],
    'mst.html':             ['shortest-path.html', 'union-find.html', 'greedy.html'],
    'topo-sort.html':       ['scc.html', 'shortest-path.html', 'bfs.html'],
    'scc.html':             ['topo-sort.html', 'bipartite.html', 'tarjan'],
    'bipartite.html':       ['network-flow.html', 'hungarian', 'dfs.html'],
    'network-flow.html':    ['bipartite.html', 'shortest-path.html', 'dfs.html'],
    'lca.html':             ['tree-dp.html', 'union-find.html', 'dfs.html'],
    'euler.html':           ['dfs.html', 'graph-rep.html', 'scc.html'],
    'kmp.html':             ['hash.html', 'trie.html', 'manacher.html'],
    'hash.html':            ['kmp.html', 'trie.html', 'manacher.html'],
    'trie.html':            ['hash.html', 'ac-automaton.html', 'kmp.html'],
    'ac-automaton.html':    ['trie.html', 'kmp.html', 'suffix-array.html'],
    'suffix-array.html':    ['ac-automaton.html', 'manacher.html', 'hash.html'],
    'manacher.html':        ['kmp.html', 'hash.html', 'suffix-array.html'],
    'union-find.html':      ['mst.html', 'lca.html', 'bipartite.html'],
    'segment-tree.html':    ['bit-fenwick.html', 'persistent.html', 'monotone-stack.html'],
    'bit-fenwick.html':     ['segment-tree.html', 'prefix-sum.html', 'monotone-queue.html'],
    'st-table.html':        ['segment-tree.html', 'sparse-table', 'lca.html'],
    'monotone-stack.html':  ['monotone-queue.html', 'segment-tree.html', 'dp-opt.html'],
    'monotone-queue.html':  ['monotone-stack.html', 'dp-opt.html', 'bfs.html'],
    'persistent.html':      ['segment-tree.html', 'trie.html', 'bit-fenwick.html'],
    'prime.html':           ['gcd.html', 'combinatorics.html', 'matrix.html'],
    'gcd.html':             ['prime.html', 'combinatorics.html', 'matrix.html'],
    'combinatorics.html':   ['gcd.html', 'prime.html', 'sg.html'],
    'matrix.html':          ['gcd.html', 'fft.html', 'gauss.html'],
    'sg.html':              ['bitmask-dp.html', 'combinatorics.html', 'greedy.html'],
    'gauss.html':           ['matrix.html', 'fft.html', 'gcd.html'],
    'fft.html':             ['matrix.html', 'gauss.html', 'ntt'],
    'basic-geo.html':       ['convex-hull.html', 'two-pointer.html', 'bit.html'],
    'convex-hull.html':     ['basic-geo.html', 'two-pointer.html', 'divide-conquer.html'],
    'two-pointer.html':     ['binary-search.html', 'monotone-queue.html', 'greedy.html'],
    'mo.html':              ['two-pointer.html', 'bit-fenwick.html', 'sqrt'],
    'tricks.html':          ['stl.html', 'binary-search.html', 'bit.html'],
  };

  const currentFile = window.location.pathname.split('/').pop();
  const related = RELATIONS[currentFile];
  if (related && searchIndex) {
    const crossLinks = related
      .map(f => searchIndex.find(item => item.url.endsWith(f)))
      .filter(Boolean);
    if (crossLinks.length) {
      const section = document.createElement('div');
      section.className = 'section cross-links-section';
      section.innerHTML = `
        <h2>相关算法</h2>
        <div class="cross-links-grid">
          ${crossLinks.map(item => `
            <a class="cross-link-card" href="${BASE}${item.url}">
              <span class="cross-link-cat">${item.cat}</span>
              <span class="cross-link-title">${item.title}</span>
            </a>
          `).join('')}
        </div>
      `;
      const container = document.querySelector('.container');
      if (container) container.appendChild(section);
    }
  }

  // ===== 8. Learning Progress Tracker =====
  const PROGRESS_KEY = 'algo-notes-progress';
  const STATES = ['', 'learning', 'mastered'];
  const STATE_LABELS = ['未学', '学习中', '已掌握'];

  function getProgress() {
    try { return JSON.parse(localStorage.getItem(PROGRESS_KEY)) || {}; } catch { return {}; }
  }
  function saveProgress(p) { localStorage.setItem(PROGRESS_KEY, JSON.stringify(p)); }
  function getProgressHTML(url, compact) {
    const p = getProgress();
    const state = p[url] || 0;
    const cls = STATES[state];
    const label = STATE_LABELS[state];
    if (compact) {
      return `<button class="progress-dot ${cls}" data-url="${url}" title="点击切换: ${label}"></button>`;
    }
    return `<button class="progress-badge ${cls}" data-url="${url}" title="点击切换状态">${label}</button>`;
  }

  // Progress dots on index page cards
  document.querySelectorAll('.card[href]').forEach(card => {
    const href = card.getAttribute('href');
    if (!href) return;
    const dot = document.createElement('span');
    dot.innerHTML = getProgressHTML(href, true);
    card.style.position = 'relative';
    card.appendChild(dot.firstElementChild);
  });

  // Progress badge on detail page header
  const pageHeader = document.querySelector('.page-header');
  if (pageHeader && currentFile && currentFile !== 'index.html') {
    const url = window.location.pathname.split('/').slice(-2).join('/');
    const badge = document.createElement('span');
    badge.innerHTML = getProgressHTML(url, false);
    pageHeader.appendChild(badge.firstElementChild);
  }

  // Progress summary bar on index page
  if (currentFile === 'index.html' && searchIndex) {
    const total = searchIndex.length;
    const p = getProgress();
    const mastered = Object.values(p).filter(v => v === 2).length;
    const learning = Object.values(p).filter(v => v === 1).length;
    const pct = Math.round((mastered / total) * 100);

    const bar = document.createElement('div');
    bar.className = 'progress-summary';
    bar.innerHTML = `
      <div class="progress-bar-track">
        <div class="progress-bar-fill" style="width:${pct}%"></div>
      </div>
      <div class="progress-stats">
        <span class="progress-stat mastered">已掌握 ${mastered}</span>
        <span class="progress-stat learning">学习中 ${learning}</span>
        <span class="progress-stat">未学 ${total - mastered - learning}</span>
        <span class="progress-pct">${pct}%</span>
      </div>
      <div class="progress-actions">
        <button class="progress-action-btn" id="progress-export" title="导出进度文件">
          <svg width="14" height="14" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><path d="M21 15v4a2 2 0 0 1-2 2H5a2 2 0 0 1-2-2v-4"/><polyline points="7 10 12 15 17 10"/><line x1="12" y1="15" x2="12" y2="3"/></svg>
          导出进度
        </button>
        <label class="progress-action-btn" title="导入进度文件">
          <svg width="14" height="14" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><path d="M21 15v4a2 2 0 0 1-2 2H5a2 2 0 0 1-2-2v-4"/><polyline points="17 8 12 3 7 8"/><line x1="12" y1="3" x2="12" y2="15"/></svg>
          导入进度
          <input type="file" id="progress-import" accept=".json" style="display:none">
        </label>
      </div>
    `;
    const hero = document.querySelector('.hero');
    if (hero) hero.after(bar);

    // Export
    bar.querySelector('#progress-export').addEventListener('click', () => {
      const data = JSON.stringify(getProgress(), null, 2);
      const blob = new Blob([data], { type: 'application/json' });
      const a = document.createElement('a');
      a.href = URL.createObjectURL(blob);
      a.download = 'algo-progress-' + new Date().toISOString().slice(0,10) + '.json';
      a.click();
      URL.revokeObjectURL(a.href);
    });

    // Import
    bar.querySelector('#progress-import').addEventListener('change', e => {
      const file = e.target.files[0];
      if (!file) return;
      const reader = new FileReader();
      reader.onload = () => {
        try {
          const imported = JSON.parse(reader.result);
          if (typeof imported !== 'object') throw new Error();
          saveProgress(imported);
          location.reload();
        } catch {
          alert('文件格式错误，请选择有效的进度文件');
        }
      };
      reader.readAsText(file);
    });
  }

  // Click handler: cycle progress state
  document.addEventListener('click', e => {
    const btn = e.target.closest('.progress-dot, .progress-badge');
    if (!btn) return;
    e.preventDefault();
    e.stopPropagation();
    const url = btn.dataset.url;
    const p = getProgress();
    const cur = p[url] || 0;
    const next = (cur + 1) % 3;
    if (next === 0) delete p[url]; else p[url] = next;
    saveProgress(p);

    // Update button
    btn.classList.remove('learning', 'mastered');
    if (STATES[next]) btn.classList.add(STATES[next]);
    if (btn.classList.contains('progress-badge')) btn.textContent = STATE_LABELS[next];
    btn.title = '点击切换: ' + STATE_LABELS[next];

    // Update summary bar if on index
    const summary = document.querySelector('.progress-summary');
    if (summary) {
      const total = searchIndex ? searchIndex.length : 51;
      const np = getProgress();
      const m = Object.values(np).filter(v => v === 2).length;
      const l = Object.values(np).filter(v => v === 1).length;
      const pct = Math.round((m / total) * 100);
      summary.querySelector('.progress-bar-fill').style.width = pct + '%';
      summary.querySelector('.progress-stat.mastered').textContent = '已掌握 ' + m;
      summary.querySelector('.progress-stat.learning').textContent = '学习中 ' + l;
      summary.querySelector('.progress-stat:last-of-type').textContent = '未学 ' + (total - m - l);
      summary.querySelector('.progress-pct').textContent = pct + '%';
    }
  });

  // ===== SVG helpers =====
  function copyIcon() {
    return '<svg width="15" height="15" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><rect x="9" y="9" width="13" height="13" rx="2" ry="2"/><path d="M5 15H4a2 2 0 0 1-2-2V4a2 2 0 0 1 2-2h9a2 2 0 0 1 2 2v1"/></svg>';
  }
  function checkIcon() {
    return '<svg width="15" height="15" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2.5" stroke-linecap="round" stroke-linejoin="round"><polyline points="20 6 9 17 4 12"/></svg>';
  }

  // ===== Helper: get relative base path =====
  function getBasePath() {
    const path = window.location.pathname;
    if (/\/\d{2}-[^/]+\//.test(path)) return '../';
    return '';
  }

  // ===== 9. Scroll Fade-in Animation =====
  const fadeEls = document.querySelectorAll('.fade-in');
  if (fadeEls.length && 'IntersectionObserver' in window) {
    const observer = new IntersectionObserver((entries) => {
      entries.forEach((entry, i) => {
        if (entry.isIntersecting) {
          setTimeout(() => entry.target.classList.add('visible'), i * 80);
          observer.unobserve(entry.target);
        }
      });
    }, { threshold: 0.1, rootMargin: '0px 0px -40px 0px' });
    fadeEls.forEach(el => observer.observe(el));
  } else {
    fadeEls.forEach(el => el.classList.add('visible'));
  }

  // ===== 10. Canvas Starfield (all pages) =====
  try {
  var canvas = document.createElement('canvas');
  canvas.id = 'starfield';
  canvas.style.cssText = 'position:fixed;top:0;left:0;width:100%;height:100%;pointer-events:none;z-index:0;';
  document.body.prepend(canvas);
  var ctx = canvas.getContext('2d');
  var stars = [], shootingStars = [];
  var sw, sh;

  function starResize() {
    sw = canvas.width = window.innerWidth;
    sh = canvas.height = window.innerHeight;
  }
  starResize();
  window.addEventListener('resize', starResize);

  for (var si = 0; si < 100; si++) {
    stars.push({
      x: Math.random() * sw,
      y: Math.random() * sh,
      r: Math.random() * 1.4 + 0.3,
      a: Math.random(),
      speed: Math.random() * 0.005 + 0.002,
      phase: Math.random() * Math.PI * 2
    });
  }

  function spawnShootingStar() {
    if (shootingStars.length < 2 && Math.random() < 0.006) {
      shootingStars.push({
        x: Math.random() * sw * 0.8 + sw * 0.1,
        y: Math.random() * sh * 0.35,
        len: 70 + Math.random() * 80,
        speed: 3.5 + Math.random() * 3.5,
        angle: -0.6 + Math.random() * 0.2,
        life: 1,
        decay: 0.014 + Math.random() * 0.01
      });
    }
  }

  function starDraw() {
    ctx.clearRect(0, 0, sw, sh);
    var t = Date.now() * 0.001;
    for (var i = 0; i < stars.length; i++) {
      var s = stars[i];
      var alpha = (Math.sin(t * s.speed * 200 + s.phase) + 1) * 0.35 * s.a + 0.08;
      ctx.beginPath();
      ctx.arc(s.x, s.y, s.r, 0, Math.PI * 2);
      ctx.fillStyle = 'rgba(200, 210, 240, ' + alpha + ')';
      ctx.fill();
    }
    spawnShootingStar();
    for (var j = shootingStars.length - 1; j >= 0; j--) {
      var ss = shootingStars[j];
      ss.x += Math.cos(ss.angle) * ss.speed;
      ss.y -= Math.sin(ss.angle) * ss.speed;
      ss.life -= ss.decay;
      if (ss.life <= 0 || ss.x > sw + 100 || ss.y > sh + 100 || ss.x < -100) {
        shootingStars.splice(j, 1);
        continue;
      }
      var tailX = ss.x - Math.cos(ss.angle) * ss.len * ss.life;
      var tailY = ss.y + Math.sin(ss.angle) * ss.len * ss.life;
      var grad = ctx.createLinearGradient(ss.x, ss.y, tailX, tailY);
      grad.addColorStop(0, 'rgba(108, 158, 255, ' + (ss.life * 0.85) + ')');
      grad.addColorStop(0.3, 'rgba(167, 139, 250, ' + (ss.life * 0.45) + ')');
      grad.addColorStop(1, 'rgba(108, 158, 255, 0)');
      ctx.beginPath();
      ctx.moveTo(ss.x, ss.y);
      ctx.lineTo(tailX, tailY);
      ctx.strokeStyle = grad;
      ctx.lineWidth = 1.5;
      ctx.stroke();
      ctx.beginPath();
      ctx.arc(ss.x, ss.y, 1.8, 0, Math.PI * 2);
      ctx.fillStyle = 'rgba(200, 220, 255, ' + (ss.life * 0.7) + ')';
      ctx.fill();
    }
    requestAnimationFrame(starDraw);
  }
  starDraw();
  } catch(e) { /* file:// protocol or canvas not supported — skip starfield */ }

  // ===== 11. Mouse-follow Glow (all pages) =====
  var glow = document.createElement('div');
  glow.style.cssText = 'position:fixed;width:450px;height:450px;border-radius:50%;pointer-events:none;z-index:0;' +
    'background:radial-gradient(circle,rgba(108,158,255,0.05) 0%,rgba(167,139,250,0.025) 30%,transparent 65%);' +
    'transform:translate(-50%,-50%);transition:opacity 0.4s;opacity:0;will-change:left,top;';
  document.body.appendChild(glow);
  var mx = -999, my = -999, gx = -999, gy = -999;
  document.addEventListener('mousemove', function(e) {
    mx = e.clientX; my = e.clientY;
    glow.style.opacity = '1';
  });
  document.addEventListener('mouseleave', function() {
    glow.style.opacity = '0';
    mx = -999; my = -999;
  });
  (function glowLoop() {
    gx += (mx - gx) * 0.1;
    gy += (my - gy) * 0.1;
    glow.style.left = gx + 'px';
    glow.style.top = gy + 'px';
    requestAnimationFrame(glowLoop);
  })();
})();
