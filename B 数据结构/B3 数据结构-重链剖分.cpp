#include <bits/stdc++.h>

using namespace std;
namespace DEBUG {
	void debug_out() { cerr << '\n'; }
	template <typename Head, typename... Tail>
	void debug_out(Head H, Tail... T) {
		cerr << ' ' << to_string(H);
		debug_out(T...);
	}
	#define debugif(con, ...) if(con) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
	#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
} using namespace DEBUG;
typedef long long ll;
const int N = 1e5 + 5, M = 2e5 + 5;
int n, m, r, P, val[N];
struct edges {
	int cnt, head[N], v[M], nxt[M];
	void add(const int &a, const int &b) {
		nxt[++cnt] = head[a], head[a] = cnt, v[cnt] = b;
	}
} g;

inline void mod(ll &h) {
	h %= P;
}

namespace st {
	#define lc(x) (x << 1)
	#define rc(x) (x << 1 | 1)
	ll sum[N << 2], tag[N << 2];
	void pdown(int l, int r, int p) {
		if(tag[p]) {
			int mid = (l + r) >> 1;
			sum[lc(p)] += (mid - l + 1) * tag[p], tag[lc(p)] += tag[p];
			sum[rc(p)] += (r - mid) * tag[p], tag[rc(p)] += tag[p];
			mod(sum[lc(p)]), mod(sum[rc(p)]), mod(tag[lc(p)]), mod(tag[rc(p)]);
			tag[p] = 0;
		}
	}
	void pup(int p) {
		sum[p] = sum[lc(p)] + sum[rc(p)];
		mod(sum[p]);
	}
	void update(int l, int r, int p, int x, int y, ll k) {
		if(l >= x && r <= y) {
			sum[p] += (r - l + 1) * k, tag[p] += k;
			mod(sum[p]), mod(tag[p]);
			return;
		}
		pdown(l, r, p);
		int mid = (l + r) >> 1;
		if(x <= mid) update(l, mid, lc(p), x, y, k);
		if(y > mid) update(mid + 1, r, rc(p), x, y, k);
		pup(p);
	}
	ll query(int l, int r, int p, int x, int y) {
		if(l >= x && r <= y) return sum[p];
		pdown(l, r, p);
		ll ret = 0;
		int mid = (l + r) >> 1;
		if(x <= mid) ret += query(l, mid, lc(p), x, y);
		if(y > mid) ret += query(mid + 1, r, rc(p), x, y);
		pup(p);
		return ret % P;
	}
	#undef lc
	#undef rc
}

int fa[N], dfn[N], dep[N], sz[N], hc[N], top[N], dfc;
void build(int u, int f) {
	fa[u] = f, dep[u] = dep[f] + 1, sz[u] = 1;
	for(int i = g.head[u]; i; i = g.nxt[i]) {
		int v = g.v[i];
		if(v != f) {
			build(v, u);
			sz[u] += sz[v];
			if(sz[v] > sz[hc[u]]) hc[u] = v;
		}
	}
}

int decom(int u, int t) {
	dfn[u] = ++dfc, top[u] = t;
	if(hc[u]) decom(hc[u], t);
	for(int i = g.head[u]; i; i = g.nxt[i])
		if(!dfn[g.v[i]]) decom(g.v[i], g.v[i]);
	return dfn[u];
}

void add(int x, int y, int z) {
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		st::update(1, n, 1, dfn[top[x]], dfn[x], z);
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) swap(x, y);
	st::update(1, n, 1, dfn[x], dfn[y], z);
}

ll getSum(int x, int y) {
	ll sum = 0;
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		sum += st::query(1, n, 1, dfn[top[x]], dfn[x]);
		mod(sum);
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) swap(x, y);
	sum += st::query(1, n, 1, dfn[x], dfn[y]);
	return sum % P;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> r >> P;
	for(int i = 1; i <= n; i++) cin >> val[i];
	for(int i = 1, x, y; i < n; i++) {
		cin >> x >> y;
		g.add(x, y), g.add(y, x);
	}
	build(r, 0);
	decom(r, r);
	for(int i = 1; i <= n; i++)
		st::update(1, n, 1, dfn[i], dfn[i], val[i]);
	for(int i = 1, op, x, y, z; i <= m; i++) {
		cin >> op;
		if(op == 1) {
			cin >> x >> y >> z;
			add(x, y, z);
		} else if(op == 2) {
			cin >> x >> y;
			cout << getSum(x, y) << '\n';
		} else if(op == 3) {
			cin >> x >> z;
			st::update(1, n, 1, dfn[x], dfn[x] + sz[x] - 1, z);
		} else {
			cin >> x;
			cout << st::query(1, n, 1, dfn[x], dfn[x] + sz[x] - 1) << '\n';
		}
	}

    return 0;
}
