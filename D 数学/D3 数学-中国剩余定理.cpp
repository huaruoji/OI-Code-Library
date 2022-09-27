#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 15; 
int n;
ll a[N], p[N], prod = 1, ans = 0;

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
ll phi(ll n) {
  ll m = ll(sqrt(n + 0.5));
  ll ans = n;
  for (ll i = 2; i <= m; i++)
    if (n % i == 0) {
      ans = ans / i * (i - 1);
      while (n % i == 0) n /= i;
    }
  if (n > 1) ans = ans / n * (n - 1);
  return ans;
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> p[i] >> a[i];
		prod *= p[i];
	}
	for(int i = 1; i <= n; i++) {
		ll mul = prod / p[i];
		ll inv = fpm(mul, phi(p[i]) - 1, p[i]);
		mul = fm(mul, inv, prod);
		ans += fm(mul, a[i], prod);
		ans %= prod;
	}
	cout << ans << '\n';
	
	return 0;
}
