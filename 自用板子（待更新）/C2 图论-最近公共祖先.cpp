namespace LCA {
	int lg[N<<2],dep[N],f[N][20];
	void pre() {
		for(int i=1;i<19;i++) ++lg[1<<i];
		for(int i=3;i<=n;i++) lg[i]+=lg[i-1];
	}
	void dfs(int u,int fa) {
		dep[u]=dep[fa]+1,f[u][0]=fa;
		for(int i=1;i<=lg[dep[u]];i++) f[u][i]=f[f[u][i-1]][i-1];
		int len=g[u].size();
		for(int i=0;i<len;i++) if(g[u][i]!=fa) dfs(g[u][i],u);
	}
	int get(int x,int y) {
		if(dep[x]>dep[y]) swap(x,y);
		while(dep[y]>dep[x]) y=f[y][lg[dep[y]-dep[x]]];
		if(x==y) return x;
		for(int i=lg[dep[x]];i>=0;i--) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
		return f[x][0];
	}
}
