#include <bits/stdc++.h>

using namespace std;
namespace DEBUG {
	void debug_out() { cerr << '\n'; }
	template <typename Head, typename... Tail>
	void debug_out(Head H, Tail... T) {
		cerr << ' ' << to_string(H);
		debug_out(T...);
	}
	#ifdef HRJ
	#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
	#else
	#define debug(...)
	#endif
} using namespace DEBUG;

int main() {
	#ifndef HRJ
	ios::sync_with_stdio(false); cin.tie(0);
	#endif
	double pi = acos(-1);
	double another = 1.0 - (1.0 / pi);
	another = 1.0 / another;
	for(int i = 1; i <= 50; i++) cout << floor(pi * i) << ' ';
	cout << '\n';
	for(int i = 1; i <= 50; i++) cout << floor(another * i) << ' ';

    return 0;
}
