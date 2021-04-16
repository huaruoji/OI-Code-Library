namespace sg {
	struct node {int l,r,val;} c[N*20];
	int cnt,x,k;
	int make(int l,int r) {
		int id=++cnt;
		if(l==r) {c[id].val=a[l];return id;}
		int mid=(l+r)>>1;
		c[id].l=make(l,mid),c[id].r=make(mid+1,r);
		return id;
	}
	int update(int l,int r,int id) {
		c[++cnt]=c[id],id=cnt;
		if(l==r) {c[id].val=k;return id;}
		int mid=(l+r)>>1;
		if(x<=mid) c[id].l=update(l,mid,c[id].l);
		else c[id].r=update(mid+1,r,c[id].r);
		return id;
	}
	int query(int l,int r,int id) {
		if(l==r) return c[id].val;
		int mid=(l+r)>>1;
		if(x<=mid) return query(l,mid,c[id].l);
		else return query(mid+1,r,c[id].r);
	}
}
