int size=0,first[N];
struct edges {int nxt,v,w}edge[M];
int addEdge(int u,int v,int w)
{
	edge[++size].nxt=first[u],first[u]=size;
	edge[size].v=v,edge[size].w=w;
}
