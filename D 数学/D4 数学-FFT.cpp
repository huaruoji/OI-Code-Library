struct cp {
	double x, y;
	cp(double _x = 0, double _y = 0) : x(_x), y(_y) {}
	cp operator+(const cp &b) { return cp(x + b.x, y + b.y); }
	cp operator-(const cp &b) { return cp(x - b.x, y - b.y); }
	cp operator*(const cp &b) {
		return cp(x * b.x - y * b.y, x * b.y + y * b.x);
	}
}; 

void FFT(cp *F, int type) {
	for(int i = 0; i < lim; i++)
		if(i < R[i]) swap(F[i], F[R[i]]);
	for(int i = 1; i < lim; i <<= 1) {
		cp w1(cos(pi / i), type * sin(pi / i));
		for(int j = 0; j < lim; j += i << 1) {
			cp w(1, 0);
			for(int k = 0; k < i; k++, w = w * w1) {
				cp F1 = F[j + k], F2 = w * F[j + i + k];
				F[j + k] = F1 + F2, F[j + i + k] = F1 - F2;
			}
		}
	}
	if(type == -1) for(int i = 0; i < lim; i++)
		F[i].x /= lim, F[i].y /= lim;
}
