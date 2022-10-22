struct BIT {
  int c[N];
  int query(int x) {
    int ans = 0;
    while(x) {
      ans += c[x];
      x -= x & -x;
    }
    return ans;
  }
  void update(int x, int k) {
    while(x < N) {
      c[x] += k;
      x += x & -x;
    }
  }
} T;
