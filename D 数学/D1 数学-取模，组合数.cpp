int fpm(int a, int b = D - 2, int c = D) {
	int res = 1 % c;
	while(b) {
		if(b & 1) res = (ll)res * a % c;
		b >>= 1, a = (ll)a * a % c;
	}
	return res;
}
inline int _(int a) { return a + (a >> 31 & D); }
inline void Add(int &a, ll b) { a = (a + b) % D; }
inline void Sub(int &a, ll b) { a = _((a - b) % D); }
inline void Mul(int &a, int b) { a = (ll)a * b % D; }
int inv[N], fac[N], ifac[N];
int C(int n, int m) {
	return n < m ? 0 : (ll)fac[n] * ifac[m] % D * ifac[n - m] % D;
}
void init(int n) {
	inv[1] = fac[1] = ifac[1] = fac[0] = ifac[0] = 1;
	for(int i = 2; i <= n; i++)	{
		inv[i] = (ll)(D - D / i) * inv[D % i] % D;
		fac[i] = (ll)fac[i - 1] * i % D;
		ifac[i] = (ll)ifac[i - 1] * inv[i] % D;
	}
}
