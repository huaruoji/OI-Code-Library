#include <bits/stdc++.h>

using namespace std;
namespace fastInput {
	#define getchar() (S == T && (T = (S = B) + fread(B, 1, 1 << 16, stdin), S == T) ? EOF : *S++)
	char B[1 << 16], *S = B, *T = B;
	template<typename Tp> inline void read(Tp &o) {
		o = 0; bool s = 0; char c = getchar();
		while(c > '9' || c < '0') s |= c == '-', c = getchar();
		while(c >= '0' && c <= '9') o = o * 10 + c - '0', c = getchar();
		if(s) o = -o;
	}
} using fastInput::read;
const int N = 1e7 + 5;
int n, top, stk[N], v[N], ls[N], rs[N];

int main() {
	read(n);
	for(int i = 1; i <= n; i++) read(v[i]);
	for(int i = 1; i <= n; i++) {
		while(top && v[stk[top]] > v[i]) ls[i] = stk[top--];
		if(top) rs[stk[top]] = i;
		stk[++top] = i;
	}
	long long r1 = 0, r2 = 0;
	for(int i = 1; i <= n; i++) 
		r1 ^= (long long)i * (ls[i] + 1),
		r2 ^= (long long)i * (rs[i] + 1);
	cout << r1 << ' ' << r2 << '\n';

	return 0;
}
