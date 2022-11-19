#include <bits/stdc++.h>

using namespace std;
#ifdef HRJ
#include "debug.h"
#else
#define debug(...)
#endif
struct FastReader {
  // attention: once you use fin you can not use cin or scanf anymore.
  char B[1 << 16], *S = B, *T = B;
  inline char getchar() {
    return S == T && (T = (S = B) + fread(B, 1, 1 << 16, stdin), S == T) ? EOF
                                                                         : *S++;
  }
  template<typename Tp> FastReader &operator>>(Tp &o) {
    o = 0;
    bool s = 0;
    char c = getchar();
    while(c > '9' || c < '0') s |= c == '-', c = getchar();
    while(c >= '0' && c <= '9') o = o * 10 + c - '0', c = getchar();
    if(s) { o = -o; }
    return *this;
  }
} fin;
struct ModInt {
  static unsigned M;
  unsigned x;
  ModInt() : x(0U) {}
  ModInt(unsigned x_) : x(x_ % M) {}
  ModInt(unsigned long long x_) : x(x_ % M) {}
  ModInt(int x_)
      : x(((x_ %= static_cast<int>(M)) < 0) ? (x_ + static_cast<int>(M)) : x_) {
  }
  ModInt(long long x_)
      : x(((x_ %= static_cast<long long>(M)) < 0)
              ? (x_ + static_cast<long long>(M))
              : x_) {}
  ModInt &operator+=(const ModInt &a) {
    x = ((x += a.x) >= M) ? (x - M) : x;
    return *this;
  }
  ModInt &operator-=(const ModInt &a) {
    x = ((x -= a.x) >= M) ? (x + M) : x;
    return *this;
  }
  ModInt &operator*=(const ModInt &a) {
    x = (static_cast<unsigned long long>(x) * a.x) % M;
    return *this;
  }
  ModInt &operator/=(const ModInt &a) { return (*this *= a.inv()); }
  ModInt pow(long long e) const {
    if(e < 0) return inv().pow(-e);
    ModInt a = *this, b = 1U;
    for(; e; e >>= 1) {
      if(e & 1) b *= a;
      a *= a;
    }
    return b;
  }
  ModInt inv() const {
    unsigned a = M, b = x;
    int y = 0, z = 1;
    for(; b;) {
      const unsigned q = a / b;
      const unsigned c = a - q * b;
      a = b;
      b = c;
      const int w = y - static_cast<int>(q) * z;
      y = z;
      z = w;
    }
    assert(a == 1U);
    return ModInt(y);
  }
  ModInt operator+() const { return *this; }
  ModInt operator-() const {
    ModInt a;
    a.x = x ? (M - x) : 0U;
    return a;
  }
  ModInt operator+(const ModInt &a) const { return (ModInt(*this) += a); }
  ModInt operator-(const ModInt &a) const { return (ModInt(*this) -= a); }
  ModInt operator*(const ModInt &a) const { return (ModInt(*this) *= a); }
  ModInt operator/(const ModInt &a) const { return (ModInt(*this) /= a); }
  template<class T> friend ModInt operator+(T a, const ModInt &b) {
    return (ModInt(a) += b);
  }
  template<class T> friend ModInt operator-(T a, const ModInt &b) {
    return (ModInt(a) -= b);
  }
  template<class T> friend ModInt operator*(T a, const ModInt &b) {
    return (ModInt(a) *= b);
  }
  template<class T> friend ModInt operator/(T a, const ModInt &b) {
    return (ModInt(a) /= b);
  }
  explicit operator bool() const { return x; }
  bool operator==(const ModInt &a) const { return (x == a.x); }
  bool operator!=(const ModInt &a) const { return (x != a.x); }
  friend std::ostream &operator<<(std::ostream &os, const ModInt &a) {
    return os << a.x;
  }
};
unsigned ModInt::M;
#define fi first
#define se second
#define mp make_pair
#define eb emplace_back
#define all(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;
template<typename T> inline void cmin(T &a, T b) {
  if(a > b) a = b;
}
template<typename T> inline void cmax(T &a, T b) {
  if(a < b) a = b;
}

int main() { return 0; }
