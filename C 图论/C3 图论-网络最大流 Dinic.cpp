#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 205, E = 10010;
int n, m, s, t;

struct Dinic {
  struct edges {
    int v, f, nxt;
  } e[E];
  int cnt = 1, hd[E], nhd[E];
  void adde(int u, int v, int f) {
    e[++cnt].v = v, e[cnt].f = f, e[cnt].nxt = hd[u], hd[u] = cnt;
    e[++cnt].v = u, e[cnt].f = 0, e[cnt].nxt = hd[v], hd[v] = cnt;
  }
  int n, S, T, d[N];
  bool bfs() {
    for (int i = 1; i <= n; i++) d[i] = 0;
    queue<int> q;
    q.push(S), d[S] = 1;
    while (!q.empty()) {
      int u = q.front();
      q.pop(), nhd[u] = hd[u];
      for (int i = hd[u]; i; i = e[i].nxt) {
        if (e[i].f && !d[e[i].v])
          d[e[i].v] = d[u] + 1, q.push(e[i].v);
      }
    }
    return d[T];
  }
  ll dfs(int u, ll flow) {
    if (u == T) return flow;
    ll rest = flow;
    for (int &i = nhd[u]; i; i = e[i].nxt) {
      int v = e[i].v;
      if (e[i].f && d[v] == d[u] + 1) {
        ll k = dfs(v, min(rest, (ll)e[i].f));
        if (!k) d[v] = 0;
        rest -= k, e[i].f -= k, e[i ^ 1].f += k;
        if (!rest) break;
      }
    }
    return flow - rest;
  }
  ll solve() {
    ll maxFlow = 0, flow;
    while (bfs())
      while ((flow = dfs(S, 1e18))) maxFlow += flow;
    return maxFlow;
  }
} net;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> s >> t;
  for (int i = 1, u, v, w; i <= m; i++) {
    cin >> u >> v >> w;
    net.adde(u, v, w);
  }
  net.n = n, net.S = s, net.T = t;
  cout << net.solve() << '\n';

  return 0;
}