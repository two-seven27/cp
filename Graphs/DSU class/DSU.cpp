class DSU {
public:
    vi rank, parent, size;
    int diff;

    DSU(int n) {
        rank.assign(n,0);
        parent.resize(n);
        size.assign(n,1);
        diff = n;
        rep(i, 0, n) parent[i] = i;
    }

    int find(int u) {
        return parent[u] == u ? u :  parent[u] = find(parent[u]);
    }

    void union_rank(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return;

        if (rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        if (rank[u] == rank[v]) rank[u]++;
        diff--;
    }

    void union_size(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return;

        if (size[u] < size[v]) swap(u, v);
        parent[v] = u;
        size[u] += size[v];
        diff--;
    }

    int get_size(int u) {
        return size[find(u)];
    }
};
