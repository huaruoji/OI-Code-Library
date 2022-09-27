#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll fm(ll a, ll b, ll c) {
	ll ans = 0;
	while(b) {
		if(b & 1) ans = (ans + a) % c;
		b >>= 1;
		a = (a + a) % c;
	}
	return ans % c;
}

ll fpm(ll a, ll b, ll c) {
	ll ans = 1;
	while(b) {
		if(b & 1) ans = fm(ans, a, c);
		b >>= 1;
		a = fm(a, a, c);
	}
	return ans % c;
}


bool MillerRabin(ll p, int testTime = 20) {
	if(p < 3) return p == 2;
	else if(p % 2 == 0) return false;
	ll u = p - 1, t = 0;
	while(u % 2 == 0) ++t, u /= 2;
	for(int i = 1, j; i <= testTime; i++) {
		ll b = rand() % (p - 1) + 1, v = fpm(b, u, p);
		if(v == 1 || v == p - 1) continue;
		for(j = 1; j <= t; j++) {
			v = fm(v, v, p);
			if(v == p - 1) break;
		}
		if(j > t) return false;
	}
	return true;
}

int main() {
	srand(time(0));
	ll n;
	cin >> n;
	for(int i = n; i <= n + 100; i++) {
		if(MillerRabin(i)) cout << i << '\n';
//		debugif(MillerRabin(i), i);
	}
//	if(MillerRabin(n)) cout << "Y\n";
//	else cout << "N\n";
		
	return 0;
}
