#include <bits/stdc++.h>

using namespace std;
namespace fastInput {
#define getchar() (S == T && (T = (S = B) + fread(B, 1, 1 << 16, stdin), S == T) ? EOF : *S++)
char B[1 << 16], *S = B, *T = B;
template <typename Tp> inline void read(Tp &o) {
  o = 0;
  bool s = 0;
  char c = getchar();
  while (c > '9' || c < '0') s |= c == '-', c = getchar();
  while (c >= '0' && c <= '9') o = o * 10 + c - '0', c = getchar();
  if (s) o = -o;
}
}
using fastInput::read;
#define mp make_pair
typedef pair<int, int> pii;
const int N = 5005, E = (5e4 + 5) * 2, MAXC = INT_MAX / 2, MAXF = INT_MAX;
int n, m, s, t;
struct PrimalDual {
  int n, s, t, maxf, minc;
  int vis[N], h[N], dis[N];
  struct edge {
    int v, f, c, nxt;
  } e[E];
  int cnt = 1, hd[N];
  void adde(int u, int v, int f, int c) {
    e[++cnt].v = v, e[cnt].f = f, e[cnt].c = c;
    e[cnt].nxt = hd[u], hd[u] = cnt;
    e[++cnt].v = u, e[cnt].f = 0, e[cnt].c = -c;
    e[cnt].nxt = hd[v], hd[v] = cnt;
  }
  void spfa() {
    queue<int> q;
    for (int i = 1; i <= n; i++) h[i] = MAXC;
    h[s] = 0, vis[s] = 1, q.push(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop(), vis[u] = 0;
      for (int i = hd[u]; i; i = e[i].nxt) {
        int v = e[i].v;
        if (e[i].f && h[v] > h[u] + e[i].c) {
          h[v] = h[u] + e[i].c;
          if (!vis[v]) vis[v] = 1, q.push(v);
        }
      }
    }
  }
  struct path {
    int v, e;
  } p[N];
  struct node {
    int dis, id;
    bool operator<(const node &a) const {
      return dis > a.dis;
    }
  };
  bool dijkstra() {
    priority_queue<node> q;
    for (int i = 1; i <= n; i++) dis[i] = MAXC, vis[i] = false;
    dis[s] = 0, q.push(node{0, s});
    while (!q.empty()) {
      int u = q.top().id;
      q.pop();
      if (vis[u]) continue;
      vis[u] = true;
      for (int i = hd[u]; i; i = e[i].nxt) {
        int v = e[i].v, nc = e[i].c + h[u] - h[v];
        if (e[i].f && dis[v] > dis[u] + nc) {
          dis[v] = dis[u] + nc;
          p[v].v = u, p[v].e = i;
          if (!vis[v]) q.push(node{dis[v], v});
        }
      }
    }
    return dis[t] != MAXC;
  }
  pair<int, int> solve() {
    spfa();
    while (dijkstra()) {
      int minf = MAXF;
      for (int i = 1; i <= n; i++) h[i] += dis[i];
      for (int i = t; i != s; i = p[i].v) minf = min(minf, e[p[i].e].f);
      for (int i = t; i != s; i = p[i].v)
        e[p[i].e].f -= minf, e[p[i].e ^ 1].f += minf;
      maxf += minf, minc += minf * h[t];
    }
    return mp(maxf, minc);
  }
} net;

int main() {
  read(n), read(m), read(s), read(t);
  for (int i = 1, u, v, f, c; i <= m; i++) {
    read(u), read(v), read(f), read(c);
    net.adde(u, v, f, c);
  }
  net.n = n, net.s = s, net.t = t;
  auto ans = net.solve();
  cout << ans.first << ' ' << ans.second;

  return 0;
}