namespace sgp
{
	int x,y,ls[N<<2],rs[N<<2];
	ll ans[N<<2],tag[N<<2];
	void pre() {for(int i=1;i<=n<<2;i++) ans[i]=pri[i],ls[i]=i<<1,rs[i]=i<<1|1;}
	void build(int l,int r,int p)
	{
		if(l==r) {ans[p]=pri[l];return;}
		int mid=(l+r)>>1;
		build(l,mid,ls[p]),build(mid+1,r,rs[p]),ans[p]=ans[ls[p]]+ans[rs[p]];
	}
	void update(int l,int r,int p,int k)
	{
		if(l>=x && r<=y) {tag[p]+=k;return;}
		ans[p]+=(min(r,y)-max(l,x)+1)*k;
		int mid=(l+r)>>1; 
		if(x<=mid) update(l,mid,ls[p],k); 
		if(y>mid) update(mid+1,r,rs[p],k);
	}
	ll query(int l,int r,int p)
	{
		if(l>=x && r<=y) return ans[p]+(r-l+1)*tag[p];
		ll res=(min(r,y)-max(l,x)+1)*tag[p];
		int mid=(l+r)>>1; 
		if(x<=mid) res+=query(l,mid,ls[p]); 
		if(y>mid) res+=query(mid+1,r,rs[p]);
		return res;
	}
}
