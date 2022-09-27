//ax = 1 (mod p)
int dayan(int x,int p) {
	a[0][1]=x,a[1][1]=p;
	a[0][0]=1,a[1][0]=0;
	int sta=1;
	while(a[0][1]!=1 && a[1][1]!=1 && a[0][1]!=0 && a[1][1]!=0) {
		if(sta==1) {
			int s=a[1][1]/a[0][1],y=a[1][1]%a[0][1];
			a[1][0]+=s*a[0][0],a[1][1]=y;
			sta=0;
		} else {
			int s=a[0][1]/a[1][1],y=a[0][1]%a[1][1];
			a[0][0]+=s*a[1][0],a[0][1]=y;
			sta=1;
		}
	}
	if(a[0][1]==1) return a[0][0];
	else if(a[1][1]==1) return -a[1][0];
	else if(a[1][1]==0) return a[0][0];
	else return -a[1][0];
}
