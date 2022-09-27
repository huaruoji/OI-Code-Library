// 思路是先把分母为 0 给判掉，然后就能愉快的玩耍 
struct frac {
	int p, q;
	frac(int p_ = 0, int q_ = 0) : p(p_), q(q_) { }
};
inline int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
inline frac simplify(frac t) {
	int d = gcd(t.p, t.q);
	return frac(t.p / d, t.q / d);
}
inline frac operator+(const frac &a, const frac &b) {
	if(a.q == 0 || b.q == 0) return frac(a.p + b.p, a.q + b.q);
	int d = gcd(a.q, b.q), lcm = a.q / d * b.q;
	return simplify(frac(lcm / a.q * a.p + lcm / b.q * b.p, lcm));
}
inline frac operator/(const frac &a, const int &b) {
	if(a.q == 0) return a;
	return simplify(frac(a.p, b * a.q));
}
