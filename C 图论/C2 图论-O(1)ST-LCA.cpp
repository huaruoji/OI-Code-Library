struct Tree {
  static const int MH = 18;
  int dfc, idx, dfn[N], fa[N], d[N], f[N << 1][MH + 1], q[N << 1], lg2[N << 1];
  vector<int> g[N];
  void dfs(int u, int f) {
    d[u] = d[f] + 1, q[++idx] = u;
    dfn[u] = idx, fa[u] = f;
    for(int v : g[u]) {
      if(v == f) continue;
      dfs(v, u), q[++idx] = u;
    }
  }
  int lca(int u, int v) {
    u = dfn[u], v = dfn[v];
    if(u > v) swap(u, v);
    int k = lg2[v - u + 1], f1 = f[u][k], f2 = f[v - (1 << k) + 1][k];
    return d[f1] < d[f2] ? f1 : f2;
  }
  void build() {
    dfs(1, 0);
    for(int i = 2; i <= idx; i++) lg2[i] = lg2[i >> 1] + 1, f[i][0] = q[i];
    for(int j = 1; j <= MH; j++) {
      for(int i = 1; i + (1 << j) <= idx; i++) {
        int f1 = f[i][j - 1], f2 = f[i + (1 << (j - 1))][j - 1];
        f[i][j] = d[f1] < d[f2] ? f1 : f2;
      }
    }
  }
} T;
