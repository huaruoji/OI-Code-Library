namespace hp {
	#define ls c[x].l
	#define rs c[x].r
	struct node {
		int l,r,f,val,d;
	}c[N];
	int find(int x) {
		if(c[x].f!=x) c[x].f=find(c[x].f);
		return c[x].f;
	}
	int merge(int x,int y) {
		if(!x||!y) return x+y;
		if(c[x].val>c[y].val || (c[x].val==c[y].val && x>y)) swap(x,y);
		rs=merge(rs,y);
		if(c[ls].d<c[rs].d) swap(ls,rs);
		c[ls].f=c[rs].f=x,c[x].d=c[rs].d+1;
		return x;
	}
	void del(int x) {
		c[x].val=-1,c[ls].f=ls,c[rs].f=rs;
		c[x].f=merge(ls,rs);
	}
}
