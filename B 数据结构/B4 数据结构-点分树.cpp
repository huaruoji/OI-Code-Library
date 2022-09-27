#include <bits/stdc++.h>

using namespace std;
namespace DEBUG {
	void debug_out() { cerr << '\n'; }
	template <typename Head, typename... Tail>
	void debug_out(Head H, Tail... T) { cerr << ' ' << H, debug_out(T...); }
	#define debug(...) cerr << '[' << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
} using namespace DEBUG;
namespace fastInput {
	#define getchar() (S == T && (T = (S = B) + fread(B, 1, 1 << 16, stdin), S == T) ? EOF : *S++)
	char B[1 << 16], *S = B, *T = B;
	template<typename Tp> inline void read(Tp &o) {
		o = 0; bool s = 0; char c = getchar();
		while(c > '9' || c < '0') s |= c == '-', c = getchar();
		while(c >= '0' && c <= '9') o = o * 10 + c - '0', c = getchar();
		if(s) o = -o;
	}
} using fastInput::read;
template<typename T> inline void cmax(T &a, T b) { if(a < b) a = b; }
const int N = 1e5 + 5;
int n, m, a[N];
vector<int> g[N];
int dep[N], st[20][N * 2], lg2[N * 2], id[N], cnt;
#define gmin(x, y) (dep[x] < dep[y] ? x : y)
void dfs(int u, int f, int d) {
	dep[u] = d, st[0][++cnt] = u, id[u] = cnt;
	for(int v : g[u]) {
		if(v == f) continue;
		dfs(v, u, d + 1);
		st[0][++cnt] = u;
	}
}
void buildST() {
	for(int i = 2; i <= cnt; i++) lg2[i] = lg2[i >> 1] + 1;
	for(int i = 1; 1 << i <= cnt; i++) {
		int w = 1 << (i - 1);
		for(int j = cnt - 2 * w + 1; j >= 1; j--)
			st[i][j] = gmin(st[i - 1][j], st[i - 1][j + w]);
	}
}
int getLCA(int x, int y) {
	x = id[x], y = id[y];
	if(x > y) swap(x, y);
	int k = lg2[y - x + 1];
	return gmin(st[k][x], st[k][y - (1 << k) + 1]);
}
int getDis(int x, int y) {
	return dep[x] + dep[y] - 2 * dep[getLCA(x, y)];
}
int sz[N], mxs[N], dfa[N], dsz[N], vis[N];
int getCt(int u, int f, int tot) {
	sz[u] = 1, mxs[u] = 0;
	int ct = 0;
	for(int v : g[u]) {
		if(vis[v] || v == f) continue;
		int vct = getCt(v, u, tot);
		if(!ct || mxs[vct] < mxs[ct]) ct = vct;
		sz[u] += sz[v], cmax(mxs[u], sz[v]);
	}
	cmax(mxs[u], tot - sz[u]);
	if(!ct || mxs[u] < mxs[ct]) ct = u;
	return ct;
}
void divide(int ct, int tot) {
	vis[ct] = 1, dsz[ct] = tot;
	for(int v : g[ct]) {
		if(vis[v]) continue;
		int vsz = sz[v], vct = getCt(v, ct, vsz);
		dfa[vct] = ct, divide(vct, vsz);
	}
}
struct node {
	int sum, lc, rc;
} c[N * 80];
int ncnt;
struct segmentTree {
	#define lc(x) c[x].lc
	#define rc(x) c[x].rc
	int rt;
	void modify(int &o, int l, int r, int x, int k) {
		if(!o) o = ++ncnt;
		c[o].sum += k;
		if(l == r) return;
		int mid = (l + r) >> 1;
		if(x <= mid) modify(lc(o), l, mid, x, k);
		else modify(rc(o), mid + 1, r, x, k);
	}
	int query(int &o, int l, int r, int x, int y) {
		if(!o) return 0;
		if(l >= x && r <= y) return c[o].sum;
		int mid = (l + r) >> 1, res = 0;
		if(x <= mid) res += query(lc(o), l, mid, x, y);
		if(y > mid) res += query(rc(o), mid + 1, r, x, y);
		return res;
	}
	#undef lc
	#undef rc
} T1[N], T2[N];
void modify(int x, int k) {
	int now = x;
	while(now) {
		int fa = dfa[now];
		T1[now].modify(T1[now].rt, 0, dsz[now], getDis(now, x), k);
		if(fa) T2[now].modify(T2[now].rt, 0, dsz[fa], getDis(fa, x), k);
		now = fa;
	}
}
int query(int x, int k) {
	int res = 0, now = x, lst = 0;
	while(now) {
		int d = getDis(now, x);
		if(d <= k) {
			res += T1[now].query(T1[now].rt, 0, dsz[now], 0, k - d);
			if(lst) res -= T2[lst].query(T2[lst].rt, 0, dsz[now], 0, k - d);
		}
		lst = now, now = dfa[now];
	}
	return res;
}

int main() {
	read(n), read(m);
	for(int i = 1; i <= n; i++) read(a[i]);
	for(int i = 1, x, y; i < n; i++) {
		read(x), read(y);
		g[x].emplace_back(y), g[y].emplace_back(x);
	}
	dfs(1, 0, 0);
	buildST();
	int ct = getCt(1, 0, n);
	divide(ct, n);
	for(int i = 1; i <= n; i++) modify(i, a[i]);
	for(int i = 1, ans = 0, op, x, y; i <= m; i++) {
		read(op), read(x), read(y);
		x ^= ans, y ^= ans;
		if(op == 0) cout << (ans = query(x, y)) << '\n';
		else modify(x, y - a[x]), a[x] = y;
	}

	return 0;
}
