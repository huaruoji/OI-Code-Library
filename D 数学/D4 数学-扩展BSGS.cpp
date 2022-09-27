#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a, m, p;

ll gcd(ll a, ll b) {
	if(b == 0) return a;
	return gcd(b, a % b);
}
void gcd(ll a, ll b, ll &x, ll &y) {
	if(b == 0) {
		x = 1, y = 0;
		return;
	}
	gcd(b, a % b, x, y); ll t = y;
	y = x - (a / b) * y, x = t;
}

ll inv(ll a, ll p) {
	a %= p;
	ll x, y;
	gcd(a, p, x, y);
	return (x % p + p) % p;
}

map<ll, ll> has;
ll BSGS(ll a, ll m, ll p) {
	has.clear();
	a %= p, m %= p;
	ll K = ceil(sqrt(p)), s = 1;
	for(int i = 1; i <= K; i++) {
		s = s * a % p;
		m = m * a % p;
		has[m] = i;
	}
	a = s;
	for(int i = 1; i <= K; i++) {
		if(has.count(a)) return i * K - has[a];
		a = a * s % p;
	}
	return -1;
}

ll exBSGS(ll a, ll m, ll p) {
	a %= p, m %= p;
	if(m == 1) return 0;
	ll k = 0, ad = 1, d = gcd(a, p);
	while(d > 1) {
		if(m % d != 0) return -1;
		++k, m /= d, p /= d, ad = ad * (a / d) % p, d = gcd(a, p);
		if(ad == m) return k;
	}
	ll ans = BSGS(a, inv(ad, p) * m % p, p);
	if(ans == -1) return -1;
	else return ans + k;
}

int main() {
	#ifdef ONLINE_JUDGE
	ios::sync_with_stdio(false); cin.tie(0);
	#endif
	while(cin >> a >> p >> m && a) {
		ll ans = exBSGS(a, m, p);
		if(ans == -1) cout << "No Solution\n";
		else cout << ans << '\n'; 
	}
	
	return 0;
}
