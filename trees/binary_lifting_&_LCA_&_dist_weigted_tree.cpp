int l = ceil_log(n, 2);
int timer = 0;

// tin/tout for ancestor checks
vector<int> tin(n+1), tout(n+1);

// up[v][j] = 2^j-th ancestor of v
vector<vector<int>> up(n+1, vector<int>(l+1));

// depth[v] = unweighted depth (#edges from root)
vector<int> depth(n+1);

// dist_from_root[v] = sum of weights on the path from root → v
vector<long long> dist_from_root(n+1, 0);

// (1) Build a recursive lambda that does DFS on the weighted tree:
auto dfs = [&](auto&& self, int v, int p) -> void {
    tin[v] = ++timer;
    up[v][0] = p;

    // Build the binary‐lifting table:
    for(int j = 1; j <= l; ++j) {
        up[v][j] = up[ up[v][j-1] ][j-1];
    }

    // Traverse all (neighbor, weight) pairs:
    for(auto& [u, w] : adj[v]) {
        if(u == p) continue;
        depth[u] = depth[v] + 1;
        dist_from_root[u] = dist_from_root[v] + w;
        self(self, u, v);
    }

    tout[v] = ++timer;
};

// (2) Check if u is an ancestor of v:
auto is_ancestor = [&](int u, int v) -> bool {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
};

// (3) LCA by binary lifting:
auto lca = [&](int u, int v) -> int {
    if(is_ancestor(u, v)) return u;
    if(is_ancestor(v, u)) return v;
    for(int j = l; j >= 0; --j) {
        if(!is_ancestor(up[u][j], v)) {
            u = up[u][j];
        }
    }
    return up[u][0];
};

// (4) Fill tin/tout, up[][], depth[] and dist_from_root[] by rooting at `root = 1`:
auto preprocess = [&]() {
    timer = 0;
    depth[1] = 0;
    dist_from_root[1] = 0;
    dfs(dfs, 1, 1);
};
preprocess();

// (5) Now a helper to get distance in O(log n):
auto distance_uv = [&](int u, int v) -> long long {
    int w = lca(u, v);
    return dist_from_root[u] + dist_from_root[v] - 2LL*dist_from_root[w];
};
    // 1 based indexing is being foloowed above
