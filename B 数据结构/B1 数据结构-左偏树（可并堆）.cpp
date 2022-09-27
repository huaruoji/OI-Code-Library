struct leftistTree {
	int val[N], d[N], lc[N], rc[N], fa[N], deled[N];
	int merge(int x, int y) {
		if(!x || !y) return x + y;
		if(val[x] > val[y] || (val[x] == val[y] && x > y)) swap(x, y);
		rc[x] = merge(rc[x], y), fa[rc[x]] = x;
		if(d[rc[x]] >= d[lc[x]]) swap(lc[x], rc[x]);
		d[x] = rc[x] ? d[rc[x]] + 1 : 0;
		return x;
	}
	int find(int x) {
		return fa[x] == x ? x : fa[x] = find(fa[x]);
	}
	void del(int x) {
		d[x] = val[x] = 0, deled[x] = 1;
		fa[lc[x]] = lc[x], fa[rc[x]] = rc[x];
		fa[x] = merge(lc[x], rc[x]);
	}
} lt;
