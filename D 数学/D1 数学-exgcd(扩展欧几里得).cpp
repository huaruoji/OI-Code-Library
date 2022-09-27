int exgcd(int a, int b, int &x, int &y) {
	if(b == 0) {
		x = 1, y = 0;
		return a;
	} 
	int d = exgcd(a, b, y, x);
	y -= a / b * x;
	return d;
}
