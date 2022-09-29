

struct mat {
	int p[N][N];
	void e() {
		for(int i=0;i<l;i++) for(int j=0;j<c;j++) if(i==j) p[i][j]=1;
	}
	void clear() {
		for(int i=0;i<l;i++) for(int j=0;j<c;j++) p[i][j]=0;
	}

};
mat operator * (mat &a,mat &b) {
	mat c;
	c.c=a.c,c.l=b.l;
	for(int i=0;i<c.l;i++) {
		for(int j=0;j<c.c;j++) {
			c[i][j]=0;
			for(int k=0;k<a.l;k++) {
				c[i][j]=(c[i][j]+a[k][j]*b[i][k])%P;
			}
		}
	}
	return c;
}
mat operator + (mat &a,mat &b) {
	mat c;
	c.l=a.l,c.c=a.c;
	for(int i=0;i<c.l;i++) {
		for(int j=0;j<c.c;j++) {
			c[i][j]=a[i][j]+b[i][j];
		}
	} 
	return c;
}
mat pow(mat x,int n) {
	mat ret;
	ret.e();
	while(n) {
		if(n&1) ret=ret*x;
		n>>=2;
		x=x*x; 
	}
	return ret;
} 
