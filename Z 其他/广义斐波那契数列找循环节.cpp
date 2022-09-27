#include <bits/stdc++.h>

using namespace std;
namespace DEBUG {
	void debug_out() { cerr << '\n'; }
	template <typename Head, typename... Tail>
	void debug_out(Head H, Tail... T) { cerr << ' ' << H, debug_out(T...); }
	#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
} using namespace DEBUG;
typedef long long ll;
ll k1 = 3, k2 = -1, a = 0, b = 1;
inline void mod(ll &a, ll p) {
	a = (a % p + p) % p;
}
bool isPrime(int x) {
	for(int i = 2; i * i <= x; i++) 
		if(!(x % i)) return false;
	return true;
}
map<pair<ll, ll>, int> mp;
int findLoop(int p) {
	mp.clear();
	mp[make_pair(a, b)] = 0;
	for(int i = 1; ; i++) {
		ll t = k1 * b + k2 * a;
		a = b, b = t;
		mod(a, p), mod(b, p);
		if(mp.find(make_pair(a, b)) != mp.end())
			return i - mp[make_pair(a, b)];
		else mp[make_pair(a, b)] = i;
	}
}

int main() {
	cin >> k1 >> k2;
	for(int i = 2; i <= 100; i++) {
		if(isPrime(i)) debug(i, findLoop(i));
	}

	return 0;
}
