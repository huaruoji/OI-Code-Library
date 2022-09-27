int gcd(int a,int b,int &m,int &n) {
	if(b==0) {m=1,n=0;return a;}
	int d=gcd(b,a%b,m,n),t=n;
	n=m-t*(a/b),m=t;
	return d;
}
