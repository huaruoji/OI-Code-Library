#include <bits/stdc++.h>

using namespace std;
const int N=1e5+5;
int n,m,s;
int vis[N],dis[N];
vector<pair<int,int> > g[N];
priority_queue<pair<int,int> > q;

void dijkstra(int s)
{
	memset(dis,0x3f,sizeof dis);
	dis[s]=0;
	q.push(make_pair(dis[s],s));
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u]++) continue;
		int len=g[u].size();
		for(int i=0;i<len;i++)
		{
			int v=g[u][i].first,w=g[u][i].second;
			if(dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				q.push(make_pair(-dis[v],v));
			}
		}
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&s);
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back(make_pair(v,w));
	}
	dijkstra(s);
	for(int i=1;i<=n;i++)
	{
		printf("%d ",dis[i]);
	}
	
	return 0;
}
