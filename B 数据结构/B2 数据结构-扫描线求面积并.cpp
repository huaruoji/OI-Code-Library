#include <bits/stdc++.h>

using namespace std;
namespace DEBUG {
	void debug_out() { cerr << '\n'; }
	template <typename Head, typename... Tail>
	void debug_out(Head H, Tail... T) { cerr << ' ' << H, debug_out(T...); }
#define debug(...) cerr << '[' << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
} using namespace DEBUG;
namespace fastInput {
//	#define getchar() (S == T && (T = (S = B) + fread(B, 1, 1 << 16, stdin), S == T) ? EOF : *S++)
	char B[1 << 16], *S = B, *T = B;
	template<typename Tp> inline void read(Tp &o) {
		o = 0; bool s = 0; char c = getchar();
		while(c > '9' || c < '0') s |= c == '-', c = getchar();
		while(c >= '0' && c <= '9') o = o * 10 + c - '0', c = getchar();
		if(s) o = -o;
	}
} using fastInput::read;
typedef long long ll;
const int N = 2e5 + 5;
int n, cnt, stN, olen[N], v[N];
struct node {
	int x, ya, yb, s;
	bool operator<(const node &b) const { return x < b.x; }
} a[N];
ll ans;

struct segmentTree {
	#define lc(x) (x << 1)
	#define rc(x) (x << 1 | 1)
	int val[N << 3], len[N << 3], cnt[N << 3];
	void build(int l, int r, int p) {
		if(l == r) {
			len[p] = olen[l];
			return;
		}
		int mid = (l + r) >> 1;
		build(l, mid, lc(p)), build(mid + 1, r, rc(p));
		len[p] = len[lc(p)] + len[rc(p)];
	}
	inline void pup(int p) {
		if(cnt[p] > 0) val[p] = len[p];
		else val[p] = val[lc(p)] + val[rc(p)];
	}
	void modify(int l, int r, int p, int x, int y, int k) {
		if(l >= x && r <= y) {
			cnt[p] += k;
			pup(p);
			return;
		}
		int mid = (l + r) >> 1;
		if(x <= mid) modify(l, mid, lc(p), x, y, k);
		if(y > mid) modify(mid + 1, r, rc(p), x, y, k);
		pup(p);
	}
	#undef lc
	#undef rc
} st;

inline int find(int x) {
	return lower_bound(v + 1, v + stN + 1, x) - v;
}

int main() {
	read(n);
	for(int i = 1, xa, xb, ya, yb; i <= n; i++) {
		read(xa), read(ya), read(xb), read(yb);
		a[i * 2 - 1] = node{xa, ya, yb, 1}, a[i * 2] = node{xb, ya, yb, -1};
		v[i * 2 - 1] = ya, v[i * 2] = yb;
	}
	sort(a + 1, a + 2 * n + 1);
	sort(v + 1, v + 2 * n + 1);
	stN = unique(v + 1, v + 2 * n + 1) - v - 2;
	for(int i = 1; i <= stN; i++) olen[i] = v[i + 1] - v[i];
	st.build(1, stN, 1);
	for(int i = 1; i <= 2 * n; i++) {
		ans += 1ll * st.val[1] * (a[i].x - a[i - 1].x);
		st.modify(1, stN, 1, find(a[i].ya), find(a[i].yb) - 1, a[i].s); 
	}
	cout << ans << '\n';

	return 0;
}
