struct CartesianTree {
  int rt, val[N], lc[N], rc[N], fa[N];
  void build(int n) {
    for(int i = 1; i <= n; i++) {
      int k = i - 1;
      while(k && val[k] > val[i]) k = fa[k]; // Ð¡¸ù¶Ñ
      lc[i] = rc[k], rc[k] = i;
      fa[i] = k, fa[lc[i]] = i;
    }
    rt = rc[0];
  }
  void clear(int n) {
    for(int i = 0; i <= n; i++) lc[i] = rc[i] = 0;
  }
} T;
