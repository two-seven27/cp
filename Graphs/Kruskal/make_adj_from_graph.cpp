// supports both 1-based and 0[based indexing
vector<vector<array<int,2>>> kruskal_adj(vector<pair<int,pi>>& edges, int n) {
    vector<vector<array<int,2>>> adj(n+1); int m = edges.size();
    sort(all(edges));
    DSU dsu(n+1);
    rep(i,0,m) {
        auto& [w,uv] = edges[i];
        auto& [u,v] = uv;
        if(dsu.find(u) == dsu.find(v)) {continue;}
        dsu.union_rank(u,v);
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    return adj;
}
