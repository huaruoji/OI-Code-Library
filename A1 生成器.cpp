#include <bits/stdc++.h>

using namespace std;
#ifdef HRJ
#include "debug.h"
#else
#define debug(...)
#endif
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
template<typename T, enable_if_t<is_integral<T>::value, bool> = 0>
T rd(T l, T r) { return uniform_int_distribution<T>(l, r)(rnd); }
template<typename T, enable_if_t<is_floating_point<T>::value, bool> = 0>
T rd(T l, T r) { return uniform_real_distribution<T>(l, r)(rnd); }

int main() {
	
  return 0;
}
