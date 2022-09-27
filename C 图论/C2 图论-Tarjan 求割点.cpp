#include <bits/stdc++.h>

using namespace std;
namespace DEBUG {
	#ifdef HRJ
	void debug_out() { cerr << '\n'; }
	template <typename Head, typename... Tail>
	void debug_out(Head H, Tail... T) {
		cerr << ' ' << to_string(H);
		debug_out(T...);
	}
	#define debugif(con, ...) if(con) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
	#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
	#else
	#define debugif(...)
	#define debug(...)
	#endif
} using namespace DEBUG;
const int N = 2e4 + 5;
int n, m, cnt, CutCnt, dfn[N], low[N], cut[N];
vector<int> g[N];

void tarjan(int u, int rt) {
	dfn[u] = low[u] = ++cnt;
	int NowCnt = 0;
	for(int &v : g[u]) {
		if(!dfn[v]) {
			tarjan(v, rt);
			low[u] = min(low[u], low[v]);
			if(dfn[u] <= low[v]) ++NowCnt;
//			debug(u, v, dfn[u], low[v], NowCnt);
			if((NowCnt && u != rt) || (u == rt && NowCnt >= 2)) {
				CutCnt += (cut[u] == 0) ? cut[u] = 1, 1 : 0;
			}
		} else low[u] = min(low[u], dfn[v]);
	}
}

int main() {
	#ifndef HRJ
	ios::sync_with_stdio(false); cin.tie(0);
	#endif
	cin >> n >> m;
	for(int i = 1, u, v; i <= m; i++) {
		cin >> u >> v;
		g[u].emplace_back(v), g[v].emplace_back(u);
	}
	for(int i = 1; i <= n; i++) {
		if(!dfn[i]) {
			tarjan(i, i);
		}
	}
	cout << CutCnt << '\n';
	for(int i = 1; i <= n; i++) {
		if(cut[i])
			cout << i << ' ';
	}

    return 0;
}
