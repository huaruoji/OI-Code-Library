#include<bits/stdc++.h>
#define re register 
using namespace std;
inline int read(){
	re int w=1,s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=(s<<1)+(s<<3)+(ch^48);
		ch=getchar();
	}
	return w*s;
}
const int MAXN = 104567 ;
int he[MAXN],ne[MAXN*2],to[MAXN*2],tot,w[MAXN*2];
inline void add(int x,int y,int z){
	tot++;ne[tot]=he[x];he[x]=tot;to[tot]=y;w[tot]=z;
}
int cnt[MAXN];bool vis[MAXN];
deque<int> q;
int L1,L2;
int d[MAXN];
inline void push(int x){
	if(cnt[x]&&cnt[x]<L1) q.push_front(x);
	else{
		if(q.empty()) q.push_back(x);
		else if(d[x]-L2<=d[q.front()]) q.push_front(x);
		else q.push_back(x);
 	}
 	cnt[x]++;vis[x]=true;
}
int n,m,s;
void spfa(){
	memset(d,0x3f3f3f3f,sizeof(d));
	d[s]=0;
	push(s);
	while(!q.empty()){
		int u=q.front();q.pop_front();
		vis[u]=false;
		for(re int e=he[u];e;e=ne[e]){
			int v=to[e];
			if(d[v]>d[u]+w[e]){
				d[v]=d[u]+w[e];
				if(vis[v]) continue;
				push(v);
			}
		}
		
	}
}
int main(){
	L1=100;
	L2=1000;
	n=read(),m=read(),s=read();
	re int x,y,z;
	for(re int i=1;i<=m;i++){
		x=read(),y=read(),z=read();
		add(x,y,z);
	}
	spfa();
	for(re int i=1;i<=n;i++) printf("%d ",d[i]);
	return 0;
}


