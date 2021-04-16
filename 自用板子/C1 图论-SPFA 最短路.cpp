int dis[N],vis[N],in[N];
void spfa(int s)
{
	memset(dis,0x3f,sizeof dis);
	q.push(s),dis[s]=0,vis[s]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop(),vis[u]=0;
		for(int i=first[u];i;i=edge[i].nxt)
		{
			int& v=edge[i].v,w=edge[i].w;
			if(dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				if(!vis[v]) {in[v]++;if(in[v]>n) return false;vis[v]=1;q.push(v);}
			}
		}
	}
}
