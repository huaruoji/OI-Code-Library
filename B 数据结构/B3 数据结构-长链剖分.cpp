vector<int> chain, g[N];
int son[N], len[N];
void build(int u) {
  len[u] = 1;
  for(int v : g[u]) {
    build(v);
    if(len[u] < len[v] + 1) len[u] = len[v] + 1, son[u] = v;
  }
}
void decom(int u, int t) {
  if(u == t) chain.emplace_back(len[u]);
  if(son[u]) decom(son[u], t);
  for(int v : g[u])
    if(v != son[u]) decom(v, v);
}

