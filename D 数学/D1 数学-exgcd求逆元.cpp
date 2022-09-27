
#include <bits/stdc++.h>

using namespace std;
const int MD = 1e9 + 7;

void exgcd(int a, int b, int &x, int &y) {
	if(b == 0) {
		x = 1, y = 0;
		return;
	}
	exgcd(b, a % b, y, x), y -= (a / b) * x;
}

inline int inv(int k, int p = MD) {
	static int x, y;
	exgcd(k, p, x, y);
	return x < 0 ? x + p : x;
}

int main() {
	int a;
	cin >> a;
	cout << inv(a);

	return 0;
}
