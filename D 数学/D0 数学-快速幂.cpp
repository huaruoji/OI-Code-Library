int fpm(int a, int b, int c) {
	int ans = 1 % c;
	while(b) {
		if(b & 1) ans = (ll)ans * a % c, b >>= 1;
		a = (ll)a * a % c;
	}
	return ans;
}