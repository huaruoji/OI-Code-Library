#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 3e6 + 5, P = 998244353, G = 3, iG = 332748118;
int n, m, lim = 1, l, R[N];
ll A[N], B[N];
int fpm(ll a, ll b, ll c = P) {
	ll ans = 1;
	while(b) {
		if(b & 1) ans = ans * a % c;
		a = a * a % c, b >>= 1;
	}
	return ans % c;
}
void NTT(ll *F, int type) {
	for(int i = 0; i < lim; i++)
		if(i < R[i]) swap(F[i], F[R[i]]);
	for(int i = 1; i < lim; i <<= 1) {
		ll w1 = fpm(type == 1 ? G : iG, (P - 1) / (i + i));
		for(int j = 0; j < lim; j += i << 1) {
			ll w = 1;
			for(int k = 0; k < i; k++, w = w * w1 % P) {
				ll F1 = F[j + k], F2 = w * F[j + i + k] % P;
				F[j + k] = (F1 + F2) % P, F[j + i + k] = (F1 - F2 + P) % P;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 0; i <= n; i++) cin >> A[i];
	for(int i = 0; i <= m; i++) cin >> B[i];
	while(lim <= n + m) lim <<= 1, ++l;
	for(int i = 0; i < lim; i++) R[i] = (R[i >> 1] >> 1) | ((i & 1) << (l - 1));
	NTT(A, 1), NTT(B, 1);
	for(int i = 0; i < lim; i++) A[i] = A[i] * B[i] % P;
	NTT(A, -1);
	for(int i = 0, ilim = fpm(lim, P - 2); i <= n + m; i++) 
		cout << A[i] * ilim % P << " \n"[i == n +m];
	
	return 0;
}
