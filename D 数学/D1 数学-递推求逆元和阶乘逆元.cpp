void init() {
	fac[0] = faci[0] = fac[1] = faci[1] = iv[1] = 1;
	for(int i = 2; i <= n; i++) {
		fac[i] = (ll)fac[i - 1] * i % P;
		iv[i] = (ll)(P - P / i) * iv[P % i] % P;
		faci[i] = (ll)faci[i - 1] * iv[i] % P;
	}
}
