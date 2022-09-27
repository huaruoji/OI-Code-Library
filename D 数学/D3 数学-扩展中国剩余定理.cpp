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
} using namespace fastInput;
typedef long long ll;
const int N = 1e5 + 5;
int n;
ll a[N], m[N];

ll exgcd(ll a, ll b, ll &x, ll &y) {
	if(b == 0) return x = 1, y = 0, a;
	ll d = exgcd(b, a % b, y, x);
	return y -= (a / b) * x, d;
}

inline ll lm(ll a, ll b, ll c) {
	ll ans = 0;
	while(b) {
		if(b & 1) ans = (ans + a) % c;
		b >>= 1;
		a = (a + a) % c;
	}
	return ans;
}

inline ll mod(ll x, ll y) {
	return (x % y + y) % y;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	read(n);
	for(int i = 1; i <= n; i++) read(m[i]), read(a[i]);
	ll A = a[1], M = m[1], x, y, d, newM;
	for(int i = 2; i <= n; i++) {
		d = exgcd(M, m[i], x, y), newM = m[i] / d * M;
		x = lm(mod(x, m[i]), mod((a[i] - A) / d, newM), newM);
		A = mod(A + lm(M, x, newM), newM), M = newM;
		M = newM;
	}
	cout << A << '\n';
	
	return 0;
}
