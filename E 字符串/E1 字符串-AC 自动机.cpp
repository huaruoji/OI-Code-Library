struct ahoCorasickAutomaton {
	int ch[N][26], fail[N], val[N], cnt;
	vector<int> h[N];
	vector<int> g[N];
	void insert(const string &s, int id) {
		int p = 0;
		for(char c : s) {
			if(!ch[p][c - 'a']) ch[p][c - 'a'] = ++cnt, p = cnt;
			else p = ch[p][c - 'a'];
		}
		h[p].emplace_back(id);
	}
	void getFail() {
		queue<int> q;
		for(int i = 0; i < 26; i++) if(ch[0][i]) q.push(ch[0][i]);
		while(!q.empty()) {
			int u = q.front(); q.pop();
			for(int i = 0; i < 26; i++) {
				if(ch[u][i]) fail[ch[u][i]] = ch[fail[u]][i], q.push(ch[u][i]);
				else ch[u][i] = ch[fail[u]][i];
			}
		}
		for(int i = 1; i <= cnt; i++) g[fail[i]].emplace_back(i);
	}
	void dfs(int u) {
		for(int &v : g[u]) dfs(v), val[u] += val[v];
		for(int i : h[u]) ans[i] = val[u];
	}
	void query(const string &s) {
		int p = 0;
		for(int i = 0; i <= cnt; i++) val[p] = 0;
		for(char c : s) p = ch[p][c - 'a'], ++val[p];
		dfs(0);
	}
} ac;
