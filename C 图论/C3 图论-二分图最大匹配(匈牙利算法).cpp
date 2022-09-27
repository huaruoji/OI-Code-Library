bool dfs(int u) {
	int len = g[u].size();
	for(int i = 0; i < len; i++) {
		int &v = g[u][i];
		if(!vis[v]) {
			vis[v] = true;
			if(!mat[v] || dfs(mat[v])) {
				mat[v] = u;
				return true;
			}
		}
	}
	return false;
}
