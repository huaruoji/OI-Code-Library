#include <bits/stdc++.h>

using namespace std;
void debug_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << ' ' << H, debug_out(T...); }
#define debug(...) cerr << '[' << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
namespace FI {
	#define getchar() (S == T && (T = (S = B) + fread(B, 1, 1 << 16, stdin), S == T) ? EOF : *S++)
	char B[1 << 16], *S = B, *T = B;
	template<typename Tp> inline void read(Tp &o) {
		o = 0; bool s = 0; char c = getchar();
		while(c > '9' || c < '0') s |= c == '-', c = getchar();
		while(c >= '0' && c <= '9') o = o * 10 + c - '0', c = getchar();
		if(s) o = -o;
	}
} using FI::read;
#define fi first
#define se second
#define mp make_pair
#define eb emplace_back
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> pii;
template<typename T> inline void cmin(T &a, T b) { if(a > b) a = b; }
template<typename T> inline void cmax(T &a, T b) { if(a < b) a = b; }

int main() {
	cout << "123";
  
	return 0;
}
