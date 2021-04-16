namespace sg
{
	int x,y,ls[N<<2],rs[N<<2];
	ll ans[N<<2],tag[N<<2];
	void pre() {for(int i=1;i<=n<<2;i++) ans[i]=pri[i],ls[i]=i<<1,rs[i]=i<<1|1;}
	void pd(int l,int r,int p,int mid)
	{
		if(!tag[p]) return;
		tag[ls[p]]+=tag[p],tag[rs[p]]+=tag[p];
		ans[ls[p]]+=tag[p]*(mid-l+1),ans[rs[p]]+=tag[p]*(r-mid),tag[p]=0;
	}
	void build(int l,int r,int p)
	{
		if(l==r) {ans[p]=pri[l];return;}
		int mid=(l+r)>>1;
		build(l,mid,ls[p]),build(mid+1,r,rs[p]),ans[p]=ans[ls[p]]+ans[rs[p]];
	}
	void update(int l,int r,int p,int k)
	{
		if(l>=x && r<=y) {tag[p]+=k,ans[p]+=(r-l+1)*k;return;}
		int mid=(l+r)>>1; 
		pd(l,r,p,mid);
		if(x<=mid) update(l,mid,ls[p],k); 
		if(y>mid) update(mid+1,r,rs[p],k);
		ans[p]=ans[ls[p]]+ans[rs[p]];
	}
	ll query(int l,int r,int p)
	{
		if(l>=x && r<=y) return ans[p];
		int mid=(l+r)>>1; ll res=0;
		pd(l,r,p,mid);
		if(x<=mid) res+=query(l,mid,ls[p]); 
		if(y>mid) res+=query(mid+1,r,rs[p]);
		return res;
	}
}

Data Structure Segement Tree
Define:
	l means a interval's left endpoint, r means right endpoint. 
	p and q means l and r of the interval need to be processed.
	lson or rson saves the location of a node's sons.
	ans generally stores the sum of the values in a interval.
	tag stores some operations that not necessary to be processed in 
	  child nodes at present.
	
Pretreatment operation : Save the location of each node's sons.
	for i from l to r
		i.lson <- i * 2
		i.rson <- i * 2 +1
		
Push_down operation : Make the tag of a node 0 and dispose its sons.
	define : x means the node.
	Update the tag and ans of left son and right son.
	tag[x] <- 0.
	
Update operation : Add a number to all the values in a interval.
	define : 
	interval "now" means the interval is processing now, 
	  interval "all" means the interval need to be processed.
	mid means '(l + r) / 2' rounded down value.
	x means the index of now.
	
	if now is a subrange of all then
		update now's tag and ans.
	else 
		Push_down now. //lson's and rson's ans should be correct.
		if p <= mid then Update now.lson.
		if q > mid then Update now.rson.

Query operation : Get the values'sum of a interval.
Build operation : Use a interval to build a segment tree.
