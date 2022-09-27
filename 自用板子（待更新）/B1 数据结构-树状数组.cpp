struct binaryIndexedTree
{
	int c[N];
	int lowbit(int x) {return x&(-x);}
	void update(int x,int k) {while(x<=n){c[x]+=k;x+=lowbit(x)}};
	int query(int x) {int sum=0;while(x){sum+=c[x];x-=lowbit(x)}return sum;}
}BIT;

namespace BIT
{
	int c[N];
	int lowbit(int x) {return x&(-x);}
	void update(int x,int k) {while(x<=n){c[x]+=k;x+=lowbit(x)}};
	int query(int x) {int sum=0;while(x){sum+=c[x];x-=lowbit(x)}return sum;}
}
