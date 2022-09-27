struct disjointSet
{
	int father[N],size[N];
	void pre() {for(int i=1;i<=n;i++) father[i]=i,size[i]=1;}
	int find(int x) {if(father[x]!=x) father[x]=find(father[x]); return father[x];}
	bool merge(int x,int y)
	{
		x=find(x),y=find(y);
		if(x==y) return true;
		if(size[x]>size[y]) swap(x,y);
		size[y]+=size[x],father[x]=y;
		return false;
	}
}s;

namespace ds {
	int f[N],s[N];
	void pre() {for(int i=1;i<=n;i++) f[i]=i,s[i]=1;}
	int find(int u) {return (f[u]==u)?(f[u]):(f[u]=find(f[u]));}
	bool merge(int x,int y) {
		x=find(x),y=find(y);
		if(x==y) return false;
		if(size[x]>size[y]) swap(x,y);
		s[y]+=s[x],f[x]=y;
		return true;
	}
}
