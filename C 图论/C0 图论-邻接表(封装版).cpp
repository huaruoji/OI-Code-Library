struct edges {
	int cnt, head[N], nxt[E], v[E], w[E];
	void add(const int &a, const int &b, const int &c) {
		nxt[++cnt] = head[a], head[a] = cnt;
		v[cnt] = b, w[cnt] = c;
	}
} g;

struct edges {
	int cnt, head[N], nxt[E], v[E];
	void add(const int &a, const int &b) {
		nxt[++cnt] = head[a], head[a] = cnt, v[cnt] = b;
	}
} g;
