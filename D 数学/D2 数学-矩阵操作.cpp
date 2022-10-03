typedef long long ll;
const int D = 1e9 + 7;
int _(int x) { return x + (x >> 31 & D); } // doesn't work when x = 0
void add(int &a, ll b) { a = (a + b) % D; }
void sub(int &a, ll b) { a = (a - b) % D; }
void mul(int &a, int b) { a = (ll)a * b % D; }
template<int S>
struct Mat {
	int a[S][S];
	Mat<S>(bool e = false) {
		memset(a, 0, sizeof a);
		if(e) { // 构造单位矩阵
			for(int i = 0; i < S; i++) a[i][i] = 1;
		}
	}
	Mat<S>(int b[][S]) {
		for(int i = 0; i < S; i++)
			for(int j = 0; j < S; j++)
				a[i][j] = b[i][j];
	}
	Mat<S>& operator*(const Mat<S> &b) {
		Mat<S> c;
		for(int i = 0; i < S; i++)
			for(int k = 0; k < S; k++)
				for(int j = 0; j < S; j++)
					add(c.a[i][j], (ll)a[i][k] * b.a[k][j]);
		return c;
	}
};
template<int S>
Mat<S> fpm(Mat<S> a, int b) {
	Mat<S> ans(true);
	while(b) {
		if(b & 1) ans = ans * a;
		b >>= 1, a = a * a;
	}
	return ans;
}
