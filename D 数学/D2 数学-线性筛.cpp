void sieve() {
	phi[1] = 1, flag[1] = true;
	for(int i = 1, to; i < N; i++) {
		if(!flag[i]) phi[i] = i - 1, prime[++cnt] = i;
		for(int j = 1; j <= cnt; j++) {
			to = i * prime[j];
			if(to >= N) break;
			flag[to] = true;
			if(i % prime[j] == 0) {
				phi[to] = prime[j] * phi[i];
				break;
			} else phi[to] = (prime[j] - 1) * phi[i];
		}
	}
}
