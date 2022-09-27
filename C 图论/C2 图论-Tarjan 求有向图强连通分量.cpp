int dfn[N], low[N], c[N], ins[N], stk[N], top, dfc, ct;
vector<int> S[N];
void tarjan(int u) {
	dfn[u] = low[u] = ++dfc;
	ins[u] = true, stk[++top] = u;
	for(int i = 1; i <= n; i++) {
		if(e[u][i] && !dfn[i]) {
			tarjan(i);
			low[u] = min(low[u], low[i]);
		} else if(e[u][i] && ins[i]) low[u] = min(low[u], dfn[i]);
	}
	if(low[u] == dfn[u]) {
		++ct;
		do {
			c[stk[top]] = ct, ins[stk[top]] = false;
			S[ct].emplace_back(stk[top]);
		} while(stk[top--] != u);
	}
}