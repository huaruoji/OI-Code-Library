using db = double;
db TIMES = clock();
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l, int r) {
  uniform_int_distribution<int> g(l, r);
  return g(rnd);
}
db rd(db l, db r) {
  uniform_real_distribution<db> g(l, r);
  return g(rnd);
}
void SA() {
  int now = calc(s), nxt;
  for(db T = 1e8; T >= 1e-8; T *= 0.9999) {
    db TIMET = clock();
    if((TIMET - TIMES) / CLOCKS_PER_SEC > 0.9) return;
    gen(), nxt = calc(t);
    if(exp(-(nxt - now) / T) > rd(0.0, 1.0)) {
      s = t, now = nxt;
    }
  }
}
