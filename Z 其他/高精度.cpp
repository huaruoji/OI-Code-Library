const int S = 45; 
struct bigInt {
	int num[S], len;
	void out() {
		if(len == 0) cout << 0;
		else for(int i = len; i >= 1; i--) cout << num[i];
	}
	bigInt() {
		len = 0;
		memset(num, 0, sizeof num);
	}
	bigInt(int t) {
		len = 0;
		memset(num, 0, sizeof num);
		while(t) {
			num[++len] = t % 10;
			t /= 10;
		}
	}
};
bigInt operator * (const bigInt &a, const bigInt &b) {
	bigInt ret;
	int x = 0;
	memset(ret.num, 0, sizeof ret.num);
	for(int i = 1; i <= a.len; i++) {
		for(int j = 1; j <= b.len; j++) {
			int cur = i + j - 1;
			ret.num[cur] += a.num[i] * b.num[j] + x;
			x = ret.num[cur] / 10;
			ret.num[cur] %= 10;
		}
		ret.num[i + b.len] = x, x = 0;
	}
	for(int i = S - 1; i >= 0; i--) {
		if(ret.num[i] && !ret.len) {
			ret.len = i;
			break;
		}
	}
	return ret;
}
bigInt operator + (const bigInt &a, const bigInt &b) {
	bigInt ret;
	int x = 0;
	memset(ret.num, 0, sizeof ret.num);
	int width = max(a.len, b.len);
	for(int i = 1; i <= width; i++) {
		ret.num[i] = a.num[i] + b.num[i] + x;
		x = ret.num[i] / 10;
		ret.num[i] %= 10;
	}
	ret.num[width + 1] = x, x = 0;
	for(int i = S - 1; i >= 0; i--) {
		if(ret.num[i] && !ret.len) {
			ret.len = i;
			break;
		}
	}
	return ret;
}
bool operator < (const bigInt &a, const bigInt &b) {
	if(a.len == b.len) {
		int t = a.len;
		while(a.num[t] == b.num[t]) --t;
		return a.num[t] < b.num[t];
	} else return a.len < b.len;
}
