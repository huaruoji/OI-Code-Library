struct Hash {
  static const int P1 = 1e9 + 7, P2 = 998444353, B1 = 131, B2 = 11311;
  struct P {
    int a, b;
    P(int _a = 0, int _b = 0) : a(_a), b(_b) {}
    P operator*(P o) { return P(ll(a) * o.a % P1, ll(b) * o.b % P2); }
    P operator+(P o) {
      return P(a + o.a > P1 ? a + o.a - P1 : a + o.a,
               b + o.b > P2 ? b + o.b - P2 : b + o.b);
    }
    P operator-(P o) {
      return P(a - o.a < 0 ? a - o.a + P1 : a - o.a,
               b - o.b < 0 ? b - o.b + P2 : b - o.b);
    }
    bool operator==(P o) { return a == o.a && b == o.b; }
  };
  vector<P> B, a;
  Hash(string s) {
    int n = s.size();
    B.resize(n + 1), a.resize(n + 1);
    B[0] = P(1, 1);
    for(int i = 1; i <= n; i++) B[i] = B[i - 1] * P(B1, B2);
    a[0] = P(0, 0), a[1] = P(s[0], s[0]);
    for(int i = 2; i <= n; i++)
      a[i] = a[i - 1] * P(B1, B2) + P(s[i - 1], s[i - 1]);
  }
  P get(int l, int r) { return a[r] - a[l - 1] * B[r - l + 1]; }
};
