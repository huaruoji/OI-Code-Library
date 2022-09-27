int fac[N], ifac[N], inv[N];
void init(int n) {
	fac[0] = fac[1] = ifac[0] = ifac[1] = inv[1] = 1;
	for(int i = 2; i <= n; i++) {
		inv[i] = (ll)(D - D / i) * inv[D % i] % D;
		fac[i] = (ll)fac[i - 1] * i % D;
		ifac[i] = (ll)ifac[i - 1] * inv[i] % D;
	}
}
int C(int n, int m) {
	return (ll)fac[n] * ifac[m] % D * ifac[n - m] % D;
}