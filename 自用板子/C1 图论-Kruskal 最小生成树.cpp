void kruskal()
{
	sort(a+1,a+m+1);
	for(int i=1;i<=m;i++)
	{
		if(disSet::merge(a[i].u,a[i].v)) continue;
		else ans+=a[i].l;
	}
}

define : E is edge set, v is edge's starting point, u is edge's terminal point
Kruskal algorithm
	sort E from smallest to largest
	for each edge in E
		if u and v are in a set then 
			ans <- ans + edge's value
		else then
			merge(u,v)
