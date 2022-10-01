int P1 = 1e9 + 7, P2 = 998444353;
typedef pair<int, int> Hash;
Hash base = mp(131, 11311);
Hash operator*(Hash a, Hash b) {
	return mp(ll(a.fi) * b.fi % P1, ll(a.se) * b.se % P1);
}
Hash operator-(Hash a, Hash b) {
	return mp(a.fi - b.fi < 0 ? a.fi - b.fi + P1 : a.fi - b.fi,
		a.se - b.se < 0 ? a.se - b.se + P2 : a.se - b.se);
}
