void kruskal_mst(int n, vector<pair<int, pi>>& edges) {
    sort(all(edges)); // Sort edges by weight
    DSU dsu(n + 1);    // 1-based indexing
    int mst_cost = 0;
    vector<pi> mst_edges;

    for (auto& [w, uv] : edges) {
        auto& [u, v] = uv;
        if (dsu.find(u) == dsu.find(v)) continue;
        dsu.union_rank(u, v);
        mst_cost += w;
        mst_edges.pb({u, v});
    }

    // Print the MST cost and edges
    cout << "MST Cost = " << mst_cost << "\n";
    cout << "Edges in MST:\n";
    for (auto& [u, v] : mst_edges) {
        cout << u << " - " << v << "\n";
    }
}

signed main() {
    int n, m;
    cin >> n >> m;  // number of nodes and edges

    vector<pair<int, pi>> edges; // {weight, {u, v}}

    rep(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.pb({w, {u, v}});
    }

    kruskal_mst(n, edges);
    return 0;
}
