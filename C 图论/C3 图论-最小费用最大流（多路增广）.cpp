#include <bits/stdc++.h>

using namespace std;
namespace fastInput {
	#define getchar() (S == T && (T = (S = B) + fread(B, 1, 1 << 16, stdin), S == T) ? EOF : *S++)
	char B[1 << 16], *S = B, *T = B;
	template<typename Tp> inline void read(Tp &o) {
		o = 0; bool s = 0; char c = getchar();
		while(c > '9' || c < '0') s |= c == '-', c = getchar();
		while(c >= '0' && c <= '9') o = o * 10 + c - '0', c = getchar();
		if(s) o = -o;
	}
} using fastInput::read;
const int N = 5e3 + 5, E = 1e5 + 5, MAXF = 1e9;
int n, m;
struct edges {
	int head[N], nxt[E], v[E], w[E], c[E], cnt;
	void add(int a, int b, int p, int q) {
		nxt[++cnt] = head[a], head[a] = cnt, v[cnt] = b, w[cnt] = p, c[cnt] = q;
		nxt[++cnt] = head[b], head[b] = cnt, v[cnt] = a, w[cnt] = 0, c[cnt] = -q;
	}
	edges() { cnt = 1; }
} g;
namespace MCMF {
	int n, S, T, maxFlow, minCost, dis[N], inq[N], vis[N];
	deque<int> q;
	bool SPFA() {
		for(int i = 1; i <= n; i++) inq[i] = false, dis[i] = MAXF;
		dis[T] = 0, q.push_back(T);
		while(!q.empty()) {
			int u = q.front();
			q.pop_front(), inq[u] = false;
			for(int i = g.head[u]; i; i = g.nxt[i]) {
				int v = g.v[i];
				if(g.w[i ^ 1] && dis[v] > dis[u] - g.c[i]) {
					dis[v] = dis[u] - g.c[i];
					if(!inq[v]) {
						inq[v] = true, q.push_back(v);
						if(dis[q.front()] > dis[q.back()]) swap(q.front(), q.back());
					}
				}
			}
		}
		return dis[S] < MAXF;
	}
	int dfs(int u, int flow) {
		vis[u] = true;
		if(u == T) return flow;
		int rest = flow;
		for(int i = g.head[u]; i; i = g.nxt[i]) {
			int v = g.v[i];
			if(!vis[v] && g.w[i] && dis[v] == dis[u] - g.c[i]) {
				int k = dfs(v, min(rest, g.w[i]));
				rest -= k, g.w[i] -= k, g.w[i ^ 1] += k;
				minCost += k * g.c[i];
			}
		}
		return flow - rest;
	}
	void solve() {
		maxFlow = minCost = 0;
		while(SPFA()) {
			do {
				for(int i = 1; i <= n; i++) vis[i] = false;
				maxFlow += dfs(S, INT_MAX);
			} while(vis[T]);
		}
	}
}

int main() {
	read(n), read(m), read(MCMF::S), read(MCMF::T);
	for(int i = 1, a, b, c, d; i <= m; i++) {
		read(a), read(b), read(c), read(d);
		g.add(a, b, c, d);
	}
	MCMF::n = n;
	MCMF::solve();
	cout << MCMF::maxFlow << ' ' << MCMF::minCost << '\n';

	return 0;
}
