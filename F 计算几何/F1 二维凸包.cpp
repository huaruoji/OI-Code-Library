#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int n;
struct point {
	double x, y;
	bool operator<(const point &b) const { return x < b.x; }
} a[N];
inline double K(int i, int j) { return (a[i].y - a[j].y) / (a[i].x - a[j].x); }
inline double dis(int i, int j) {
	return sqrt(pow(a[i].x - a[j].x, 2) + pow(a[i].y - a[j].y, 2));
}
int q1[N], q2[N], tl1, tl2;
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
	double ans = 0;
	for(int i = 1; i < tl1; i++) ans += dis(q1[i], q1[i + 1]);
	for(int i = 1; i < tl2; i++) ans += dis(q2[i], q2[i + 1]);
	if(a[q1[1]].x == a[q2[1]].x) ans += a[q2[1]].y - a[q1[1]].y;
	if(a[q1[tl1]].x == a[q2[tl2]].x) ans += a[q2[tl2]].y - a[q1[tl1]].y;
	cout << fixed << setprecision(2) << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i].x >> a[i].y;
	convexHull();

	return 0;
}
