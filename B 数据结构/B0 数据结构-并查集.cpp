struct DSU {
  int f[N], sz[N];
  int get(int x) {
    return f[x] == x ? x : f[x] = get(f[x]);
  }
  bool merge(int x, int y) {
    x = get(x), y = get(y);
    if (x == y) return false;
    if (sz[x] > sz[y]) swap(x, y);
    sz[y] += sz[x], f[x] = y;
    return true;
  }
  DSU(int n) {
    for (int i = 1; i <= n; i++) f[i] = i, sz[i] = 1;
  }
};