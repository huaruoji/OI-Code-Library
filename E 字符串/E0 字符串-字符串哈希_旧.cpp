typedef long long ll;
int P[2] = {100663319, 19491001}, B[2] = {11311, 131}, Bp[N][2];
struct ha {
	int c[2];
	ha() { c[0] = c[1] = 0; }
	ha(int a, int b) { c[0] = a, c[1] = b; }
	static void init() {
		Bp[0][0] = Bp[0][1] = 1;
		for(int i = 1; i <= n; i++)
			for(int j = 0; j < 1; j++)
				Bp[i][j] = (ll)Bp[i - 1][j] * B[j] % P[j];
	}
	friend ha operator*(const ha &a, int k) { 
		return ha((ll)a.c[0] * k % P[0], (ll)a.c[1] * k % P[1]); 
	}
	friend ha operator+(const ha &a, const ha &b) { 
		return ha((a.c[0] + b.c[0]) % P[0], (a.c[1] + b.c[1]) % P[1]); 
	}
	friend ha operator-(const ha &a, const ha &b) { 
		return ha((a.c[0] - b.c[0] + P[0]) % P[0], (a.c[1] - b.c[1] + P[1]) % P[1]); 
	}
	friend ha operator+(const ha &a, int k) { 
		return ha((a.c[0] + k) % P[0], (a.c[1] + k) % P[1]); 
	}
	friend ha operator<<(const ha &a, int k) { 
		return ha((ll)a.c[0] * Bp[k][0] % P[0], (ll)a.c[1] * Bp[k][1] % P[1]); 
	}
	friend ostream& operator<<(ostream &os, ha &x) {
		os << '(' << x.c[0] << ' ' << x.c[1] << ')';
		return os;
	}
	friend bool operator==(const ha &a, const ha &b) { 
		return a.c[0] == b.c[0] && a.c[1] == b.c[1]; 
	}
}
