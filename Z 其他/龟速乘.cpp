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

int main() {
	ll a, b, c;
	cin >> a >> b >> c;
	cout << fpm(a, b, c); 
	
	return 0;
}
