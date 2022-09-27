int root, cnt, sz[N], maxs[N], a[N], d[N], b[N];
bool vis[N], ok[N];
void getRoot(int u, int fa, int tot) {
	sz[u] = 1;
	maxs[u] = 0;
	for(int i = g.head[u]; i; i = g.nxt[i]) {
		int &v = g.v[i];
		if(v == fa || vis[v]) continue;
		getRoot(v, u, tot);
		sz[u] += sz[v];
		maxs[u] = max(maxs[u], sz[v]);
	}
	maxs[u] = max(maxs[u], tot - maxs[u]);
	if(!root || maxs[u] < maxs[root]) root = u;
}
void getDis(int u, int fa, int dis, int anc) {
	a[++cnt] = u;
	d[u] = dis, b[u] = anc;
	for(int i = g.head[u]; i; i = g.nxt[i]) {
		int &v = g.v[i];
		if(v == fa || vis[v]) continue;
		getDis(v, u, dis + g.w[i], anc);
	}
}
bool cmp(const int &u, const int &v) {
	return d[u] < d[v];
}
void calc(int u) {
	a[cnt = 1] = u;
	d[u] = 0, b[u] = u;
	for(int i = g.head[u]; i; i = g.nxt[i]) {
		int &v = g.v[i];
		if(vis[v]) continue;
		getDis(v, u, g.w[i], v);
	}
	sort(a + 1, a + cnt + 1, cmp);
	for(int i = 1; i <= m; i++) {
		if(ok[i]) continue;
		int l = 1, r = cnt;
		while(l < r) {
			if(d[a[l]] + d[a[r]] < k[i]) ++l;
			else if(d[a[l]] + d[a[r]] > k[i]) --r;
			else if(b[a[l]] == b[a[r]]) a[l] == a[l+1] ? ++l : --r;
			else {
				ok[i] = true;
				break;
			}
		}
	}
}
void solve(int u) {
	vis[u] = true;
	calc(u);
	for(int i = g.head[u]; i; i = g.nxt[i]) {
		int &v = g.v[i];
		if(vis[v]) continue;
		root = 0;
		getRoot(v, u, sz[v]);
		solve(root);
	}
}
