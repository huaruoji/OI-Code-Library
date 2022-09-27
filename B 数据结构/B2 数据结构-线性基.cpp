const int H = 50;
struct xorSet {
	ll a[H + 1];
	bool zero = false;
	void ins(ll x) {
		for(int i = H; ~i; i--)
			if(x & (1ll << i)) {
				if(!a[i]) return a[i] = x, void();
				else x ^= a[i];
			}
		zero = true;
	}
	bool check(ll x) {
		for(int i = H; ~i; i--)
			if(x & (1ll << i)) {
				if(!a[i]) return false;
				else x ^= a[i];
			}
		return true;
	}
	ll qmin() {
		if(zero) return 0;
		for(int i = 0; i <= H; i++)
			if(a[i]) return a[i];
		return -1;
	}
	ll qmax(ll ans = 0) {
		for(int i = H; ~i; i--)
			ans = max(ans, ans ^ a[i]);
		return ans;
	}
	void operator+=(const xorSet &b) {
		for(int i = H; ~i; i--)
			if(b.a[i]) ins(b.a[i]);
	}
};
