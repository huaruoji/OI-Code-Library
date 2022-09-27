#include <bits/stdc++.h>

using namespace std;
const int N = 1e7 + 5;
int flag[N], phi[N], mu[N], d[N], sig[N];
int q[N], pq[N], p[N], v, c;
void sieve(int n) {
	flag[1] = true, phi[1] = 1, mu[1] = 1, d[1] = 1, sig[1] = 1;
	for(int i = 2; i <= n; i++) {
		if(!flag[i]) {
			p[++c] = i, phi[i] = i - 1, mu[i] = -1, d[i] = 2, sig[i] = 1 + i;
			q[i] = 1, pq[i] = i;
		}
		for(int j = 1; j <= c && (v = i * p[j]) <= n; j++) {
			flag[v] = true;
			if(i % p[j]) {
				phi[v] = phi[p[j]] * phi[i];
				mu[v] = -mu[i]; // mu[v] = mu[p[j]] * mu[i]
				d[v] = d[p[j]] * d[i];
				sig[v] = sig[p[j]] * sig[i];
				q[v] = 1, pq[v] = p[j];
			} else {
				phi[v] = p[j] * phi[i];
				mu[v] = 0;
				d[v] = d[i] / (q[i] + 1) * (q[i] + 2);
				sig[v] = sig[i] / sig[pq[i]] * (sig[pq[i]] + pq[i] * p[j]);
				q[v] = q[i] + 1, pq[v] = pq[i] * p[j];
				break;
			}
		}
	}
}

int main() {
	sieve(1e7);
	for(int i = 1; i <= 20; i++) {
		debug(i, phi[i], mu[i], d[i], sig[i], q[i], pq[i]);
	}

	return 0;
}
