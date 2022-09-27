namespace Splay {
int sz[N], ch[N][2], cnt[N], val[N], fa[N], rt, tot;
#define lc(x) ch[x][0]
#define rc(x) ch[x][1]
inline void maintain(int x) { sz[x] = sz[lc(x)] + sz[rc(x)] + cnt[x]; }
inline bool get(int x) { return x == rc(fa[x]); } // left child -> 0; right child -> 1;
inline void clear(int x) { lc(x) = rc(x) = sz[x] = fa[x] = val[x] = cnt[x] = 0; }
void rotate(int x) {
  int y = fa[x], z = fa[y], chk = get(x);
  ch[y][chk] = ch[x][chk ^ 1];
  if (ch[x][chk ^ 1]) fa[ch[x][chk ^ 1]] = y;
  ch[x][chk ^ 1] = y;
  fa[y] = x;
  fa[x] = z;
  if (z) ch[z][y == ch[z][1]] = x;
  maintain(x);
  maintain(y);
}
void splay(int x, int g = 0) {
  for (; fa[x] != g; rotate(x))
    if (fa[fa[x]] != g) rotate(get(x) == get(fa[x]) ? fa[x] : x);
  if (g == 0) rt = x;
}
void insert(int k) {
  for (int u = rt, f = 0;; f = u, u = ch[u][val[u] < k]) {
    if (val[u] == k) {
      ++cnt[u];
      maintain(u);
      maintain(f);
      splay(u);
      break;
    } else if (!u) {
      val[++tot] = k;
      ++cnt[tot];
      fa[tot] = f;
      if (f) ch[f][val[f] < k] = tot;
      maintain(tot);
      maintain(f);
      splay(tot);
      break;
    }
  }
}
int rk(int k) {
  for (int res = 0, u = rt;;) {
    if (k < val[u]) u = lc(u);
    else {
      res += sz[lc(u)];
      if (k == val[u]) {
        splay(u);
        return res + 1;
      }
      res += cnt[u];
      u = rc(u);
    }
  }
}
int kth(int k) {
  for (int u = rt;;) {
    if (lc(u) && k <= sz[lc(u)]) u = lc(u);
    else {
      k -= cnt[u] + sz[lc(u)];
      if (k <= 0) {
        splay(u);
        return val[u];
      }
      u = rc(u);
    }
  }
}
int pre() {
  int u = lc(rt);
  while (rc(u)) u = rc(u);
  splay(u);
  return u;
}
int nxt() {
  int u = rc(rt);
  while (lc(u)) u = lc(u);
  splay(u);
  return u;
}
void del(int x) {
  rk(x);
  int u = rt;
  if (cnt[rt] > 1) --cnt[rt], maintain(rt);
  else if (!lc(rt) && !rc(rt)) clear(rt), rt = 0;
  else if (!lc(rt) || !rc(rt)) {
    rt = lc(rt) ? lc(rt) : rc(rt), fa[rt] = 0;
    clear(u);
  } else {
    int t = pre();
    fa[rc(u)] = t;
    rc(t) = rc(u);
    clear(u);
    maintain(rt);
  }
}
}
