#include <bits/stdc++.h>

using namespace std;

int euler(int x) {
	if(x == 1) return 1;
	int ans = x, tmp = x;
	for(int i = 2; i * i <= x; i++) {
		if(tmp % i == 0) ans = ans / i * (i - 1);
		while(tmp % i == 0) tmp /= i;
	}
	if(tmp > 1) ans = ans / tmp * (tmp - 1);
	return ans;
}

int main() {
	int n;
	cin >> n;
	cout << euler(n) << '\n'; 
	
	return 0;
} 
