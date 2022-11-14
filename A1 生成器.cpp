#include <bits/stdc++.h>

using namespace std;
void debug_out() { cerr << '\n'; }
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
  cerr << ' ' << H, debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
using ll = long long;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll rd(ll l, ll r) {
  uniform_int_distribution<ll> g(l, r);
  return g(rnd);
}

int main() {
  
  return 0;
}
