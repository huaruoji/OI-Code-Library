bool dfs(int u,int col) {
	int len=g[u].size();
	color[u]=col;
	for(int i=0;i<len;i++) {
		int& v=g[u][i];
		if(color[v]==color[u]) return false;
		else if(color[v]==0 && dfs(v,-col)==false) return false;
	}
	return true;
}
//color[i]为-1,0或1  -1,1表示颜色  0表示是否访问 
