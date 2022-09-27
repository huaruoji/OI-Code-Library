#include <bits/stdc++.h>

using namespace std;
const int N = 2e6 + 10, M = 2e6 + 10;
int n, m;
struct edges {
	int head[N], nxt[M], v[M], cnt;
	void add(int a, int b) {
		nxt[++cnt] = head[a], head[a] = cnt, v[cnt] = b;
	}
} g;

inline int id(int x, bool p) {
	return p ? x + n : x;
}

stack<int> s;
int dfn[N], low[N], scc[N], ins[N], sccCnt, dfsCnt;
void tarjan(int u) {
	dfn[u] = low[u] = ++dfsCnt;
	s.push(u), ins[u] = true;
	for(int i = g.head[u]; i; i = g.nxt[i]) {
		int v = g.v[i];
		if(!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if(ins[v]) low[u] = min(low[u], dfn[v]);
	}
	if(dfn[u] == low[u]) {
		for(++sccCnt; ; ) {
			int v = s.top();
			scc[v] = sccCnt, s.pop(), ins[v] = false;
			if(v == u) break;
		}
	}
}

int main() {
	#ifndef HRJ
	ios::sync_with_stdio(false); cin.tie(0);
	#endif
	cin >> n >> m;
	for(int i = 1, x, a, y, b; i <= m; i++) {
		cin >> x >> a >> y >> b;
		g.add(id(x, !a), id(y, b));
		g.add(id(y, !b), id(x, a));
	}
	for(int i = 1; i <= n << 1; i++) {
		if(!dfn[i]) tarjan(i);
	}
	for(int i = 1; i <= n; i++) {
		if(scc[id(i, 0)] == scc[id(i, 1)]) {
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}
	cout << "POSSIBLE\n";
	for(int i = 1; i <= n; i++) {
		cout << (scc[id(i, 0)] < scc[id(i, 1)] ? 0 : 1) << ' ';
	}

    return 0;
}
