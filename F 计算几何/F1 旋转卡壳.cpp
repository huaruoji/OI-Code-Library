#include <bits/stdc++.h>

using namespace std;
const int N = 5e4 + 5;
int n, ans;
struct point {
	double x, y;
	bool operator<(const point &b) const { return x < b.x; }
	bool operator!=(const point &b) const { return x != b.x || y != b.y; }
} a[N];
inline double K(int i, int j) { return (a[i].y - a[j].y) / (a[i].x - a[j].x); }
inline int dis2(int i, int j) {
	return (a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y);
}
inline int cross(point &a, point &b, point &c) {
	return 1ll * (b.x - a.x) * (c.y - a.y) - 1ll * (b.y - a.y) * (c.x - a.x);
}
int q1[N], tl1, q2[N], tl2, b[N], tlb;
void convexHull() {
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) {
		if(tl1 && a[i].x == a[q1[tl1]].x) {
			if(a[i].y < a[q1[tl1]].y) --tl1;
			else continue;
		} 
		while(tl1 > 1 && K(i, q1[tl1]) <= K(q1[tl1], q1[tl1 - 1])) --tl1;
		q1[++tl1] = i;
	}
	for(int i = 1; i <= n; i++) {
		if(tl2 && a[i].x == a[q2[tl2]].x) {
			if(a[i].y > a[q2[tl2]].y) --tl2;
			else continue;
		}
		while(tl2 > 1 && K(i, q2[tl2]) >= K(q2[tl2], q2[tl2 - 1])) --tl2;
		q2[++tl2] = i;
	}
	// 合并上凸壳和下凸壳 
	for(int i = 1; i <= tl1; i++) b[++tlb] = q1[i];
	for(int i = tl2; i >= 1; i--) 
		if(a[q2[i]] != a[b[tlb]] && a[q2[i]] != a[b[1]]) b[++tlb] = q2[i];
}
void xuan2zhuan3qia3ke2() {
	if(tlb == 2) {
		ans = dis2(b[1], b[2]);
		return; 
	}
	int p = 2;
	for(int i = 1; i < tlb; i++) {
		while(cross(a[b[i]], a[b[i + 1]], a[b[p]]) < cross(a[b[i]], a[b[i + 1]], a[b[p % tlb + 1]])) 
			p = p % tlb + 1;
		ans = max(ans, max(dis2(b[i], b[p]), dis2(b[i + 1], b[p])));
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i].x >> a[i].y;
	convexHull();
	xuan2zhuan3qia3ke2();
	cout << ans << '\n';

	return 0;
}
