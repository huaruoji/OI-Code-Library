vector<int> prime;
bool flag[N];
void sieve(int n) {
  prime.reserve(n / 10);
	for(int i = 2; i <= n; i++) {
		if(!flag[i]) prime.emplace_back(i);
		for(int p : prime) {
			int v = i * p;
			if(v > n) break;
			flag[v] = true;
			if(i % p == 0) break;
		}
	}
}
