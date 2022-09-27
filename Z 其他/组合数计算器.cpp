#include <bits/stdc++.h>

using namespace std;
namespace DEBUG {
	void debug_out() { cerr << '\n'; }
	template <typename Head, typename... Tail>
	void debug_out(Head H, Tail... T) { cerr << ' ' << H, debug_out(T...); }
	#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
} using namespace DEBUG;
typedef long long ll;
const int N = 1e5 + 5, D = 998244353;
int fpm(int a, int b = D - 2, int c = D) {
	int res = 1 % c;
	while(b) {
		if(b & 1) res = (ll)res * a % c;
		b >>= 1, a = (ll)a * a % c;
	}
	return res;
}
inline int _(int a) { return a + (a >> 31 & D); }
inline void Add(int &a, ll b) { a = (a + b) % D; }
inline void Sub(int &a, ll b) { a = _((a - b) % D); }
inline void Div(int &a, int b) { a = (ll)a * fpm(b) % D; }
inline void Mul(int &a, int b) { a = (ll)a * b % D; }
int inv[N], fac[N], ifac[N];
int C(int n, int m) {
	return n < m ? 0 : (ll)fac[n] * ifac[m] % D * ifac[n - m] % D;
}
void init(int n) {
	inv[1] = fac[1] = ifac[1] = fac[0] = ifac[0] = 1;
	for(int i = 2; i <= n; i++)	{
		inv[i] = (ll)(D - D / i) * inv[D % i] % D;
		fac[i] = (ll)fac[i - 1] * i % D;
		ifac[i] = (ll)ifac[i - 1] * inv[i] % D;
	}
}

int main() {
	init(1e5);
	int n, m;
	cin >> n >> m;
	debug(C(n, m));

	return 0;
}
