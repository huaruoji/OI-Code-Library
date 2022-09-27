void solve() {
	for (int i = 1; i <= n; i++) {
		int flag = i;
		for (int j = i; j <= n; j++) if (fabs(a[j][i]) > fabs(a[flag][i])) flag = j;
		for (int j = 1; j <= n + 1; j++) swap(a[i][j], a[flag][j]);
		if (fe(a[i][i], 0)) continue;
		for (int j = n + 1; j >= i; j--) a[i][j] /= a[i][i];
		for (int j = 1; j <= n; j++) {
			if (j == i) continue;
			double t = a[j][i];
			for (int k = i; k <= n + 1; k++) a[j][k] -= t * a[i][k];
		}
	}
}
