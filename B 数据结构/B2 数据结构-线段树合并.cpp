int merge(int x, int y) {
	if(!x || !y) return x + y;
	int o = ++cnt;
	lc[o] = merge(lc[x], lc[y]), rc[o] = merge(rc[x], rc[y]);
	// 做点什么来把 lc[o] 和 rc[o] 的信息合并到 o 上 
	return o;
}
