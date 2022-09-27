#define gmin(x, y) (d[x] < d[y] ? x : y)
int cnt, d[N], dfn[N], st[MH + 1][N << 1], q[N << 1], lg[N << 1];
void dfs(int u, int f) {
  d[u] = d[f] + 1, st[0][++cnt] = u, dfn[u] = cnt;
  for (int v : g[u]) {
    if (v == f) continue;
    dfs(v, u), st[0][++cnt] = u;
  }
}
void init() {
  dfs(1, 0);
  for (int i = 2; i <= cnt; i++) lg[i] = lg[i >> 1] + 1;
  for (int i = 1; i <= MH; i++) {
    int w = 1 << (i - 1);
    for (int j = cnt - w * 2 + 1; j >= 1; j--)
      st[i][j] = gmin(st[i - 1][j], st[i - 1][j + w]);
  }
}
int getLca(int x, int y) {
  x = dfn[x], y = dfn[y];
  if (x > y) swap(x, y);
  int k = lg[y - x + 1];
  return gmin(st[k][x], st[k][y - (1 << k) + 1]);
}
#undef gmin