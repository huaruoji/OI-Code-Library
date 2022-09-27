#include <bits/stdc++.h>

using namespace std;
namespace DEBUG {
	void debug_out() { cerr << '\n'; }
	template <typename Head, typename... Tail>
	void debug_out(Head H, Tail... T) { cerr << ' ' << H, debug_out(T...); }
	#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
} using namespace DEBUG;
const int N = 1e5 + 5;
char c[N];
int n, m, cnt, t[N], sa[N], ht[N], rk[2 * N], l[2 * N];

void buildSA() {
	m = int('z');
	for(int i = 1; i <= n; i++) ++t[rk[i] = c[i]];
	for(int i = 1; i <= m; i++) t[i] += t[i - 1];
	for(int i = n; i >= 1; i--) sa[t[rk[i]]--] = i;
	for(int k = 1; k < n; k <<= 1) {
		for(int i = n - k + 1; i <= n; i++) l[cnt = i - n + k] = i;
		for(int i = 1; i <= n; i++)
			if(sa[i] > k) l[++cnt] = sa[i] - k;
		for(int i = 1; i <= m; i++) t[i] = 0;
		// 按第二关键字排序后生成新序列 l，根据 l 来排序 
		for(int i = 1; i <= n; i++) ++t[rk[l[i]]];
		for(int i = 1; i <= m; i++) t[i] += t[i - 1];
		for(int i = n; i >= 1; i--) sa[t[rk[l[i]]]--] = l[i], l[i] = 0;
		swap(rk, l), cnt = 0;
		for(int i = 1; i <= n; i++)
			if(l[sa[i]] == l[sa[i - 1]] && l[sa[i] + k] == l[sa[i - 1] + k]) rk[sa[i]] = cnt;
			else rk[sa[i]] = ++cnt;
		if((m = cnt) == n) break;
	}
	for(int i = 1; i <= n; i++) rk[sa[i]] = i;
}
void getHeight() {
	for(int i = 1, j, k = 0; i <= n; i++) {
		if(rk[i] == 1) continue;
		k -= (k > 0), j = sa[rk[i] - 1];
		while(j + k <= n && i + k <= n && c[i + k] == c[j + k]) ++k;
		ht[rk[i]] = k;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	scanf("%s", c + 1);
	n = strlen(c + 1);
	buildSA();
	for(int i = 1; i <= n; i++) cout << sa[i] << ' ';
	
	return 0;
}
