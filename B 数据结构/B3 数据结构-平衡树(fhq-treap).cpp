namespace treap {
	#define lc(x) ch[x][0]
	#define rc(x) ch[x][1]
	
	int ch[N][2], sz[N], val[N], rnd[N], cnt, rt;
	inline void update(int p) {sz[p] = sz[lc(p)] + sz[rc(p)] + 1;}
	void preWork() {srand(time(0));}
	int newNode(int x) {
		val[++cnt] = x, sz[cnt] = 1;
		rnd[cnt] = rand(), lc(cnt) = rc(cnt) = 0;
		return cnt;
	}
	int merge(int x, int y) {
		if(!x || !y) return x | y;
		if(rnd[x] < rnd[y]) {
			rc(x) = merge(rc(x), y);
			update(x);
			return x;
		} else {
			lc(y) = merge(x, lc(y));
			update(y);
			return y;
		}
	}
	void split(int p, int v, int &x, int &y) {
		if(!p) {
			x = y = 0;
			return;
		} else if(val[p] <= v) {
			x = p;
			split(rc(x), v, rc(x), y);
			update(x);
		} else {
			y = p;
			split(lc(y), v, x, lc(y));
			update(y);
		}
	}
//	void split(int p, int v, int &x, int &y) {	
//		if(!p) {
//			x = y = 0;
//			return;
//		}
//		pushDown(p);
//		if(sz[lc(p)] < v) {
//			x = p;
//			split(rc(x), v - sz[lc(p)] - 1, rc(x), y);
//			maintain(x);
//		} else {
//			y = p;
//			split(lc(y), v, x, lc(y));
//			maintain(y);
//		}
//	}
	void ins(int &rt, int v) {
		int x = 0, y = 0, z = 0;
		split(rt, v, x, y);
		z = newNode(v);
		rt = merge(merge(x, z), y);
	}
	void del(int &rt, int v) {
		int x = 0, y = 0, z = 0;
		split(rt, v, x, y);
		split(x, v - 1, x, z);
		z = merge(lc(z), rc(z));
		rt = merge(merge(x, z), y);
	}
	int kth(int u, int v) {
		if(v == sz[lc(u)] + 1) return val[u];
		else if(v <= sz[lc(u)]) return kth(lc(u), v);
		else return kth(rc(u), v - sz[lc(u)] - 1);
	}
	int rk(int &rt, int v) {
		int x, y;
		split(rt, v-1, x, y);
		int ret = sz[x] + 1;
		rt = merge(x, y);
		return ret;
	}
	int pre(int &rt, int v) {
		int x, y, ret;
		split(rt, v - 1, x, y);
		if(!x) return -INF;
		ret = kth(x, sz[x]);
		rt = merge(x, y);
		return ret;
	}
	int nxt(int &rt, int v) {
		int x, y, ret;
		split(rt, v, x, y);
		if(!y) return INF;
		ret = kth(y, 1);
		rt = merge(x, y);
		return ret;
	}
	int find(int &rt, int v) {
		int x = 0, y = 0, z = 0, ret = 0;
		split(rt, v, x, y);
		split(x, v-1, x, z);
		if(z) ret = 1;
		rt = merge(merge(x, z), y);
		return ret;
	}
	void out(int u) {
		if(!u) return;
		out(lc(u));
		cout << u << endl;
		out(rc(u));
	}
}
