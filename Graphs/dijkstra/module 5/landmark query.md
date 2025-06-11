# 🏔 Module 5: Dijkstra for Landmark-Based or All-Pairs Shortest Paths

## 💪 Goal

Solve shortest path problems between **multiple node pairs**, using landmark-based Dijkstra variants.
Useful when:

* You have many queries for shortest paths between arbitrary nodes
* You can afford precomputation from specific nodes

---

## 📅 Problem Statement

Given a directed graph with `n` nodes and `m` edges, you need to answer `q` queries.
Each query gives two nodes `a` and `b`. Return the shortest path from `a` to `b`.

* Practice Link: [No direct CSES link; similar idea to](https://cses.fi/problemset/task/1671) or extend with multiple queries.

---

## 🧠 Intuition & Explanation

Running Dijkstra from scratch for every query is too slow if `q` is large. Instead:

### 🛤 Strategy: Landmark-Based Dijkstra

Pick a few **landmark nodes**, and run Dijkstra from each one. Store their distances to all other nodes.

Then, for each query `(a, b)`:

* Estimate `dist(a, b)` as `min_l { dist(a, l) + dist(l, b) }` for all landmarks `l`
* If `a` or `b` is a landmark, exact answer is available

This is similar to **ALT algorithm (A*, landmarks, triangle inequality)*\* used in real-world routing.

---

## ⚙️ Code: Multi-Source Dijkstra Precomputation

```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

vector<int> dijkstra(int src, vector<vector<pair<int, int>>>& adj, int n) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[src] = 0;
    pq.emplace(0, src);
    
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto &[v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    return dist;
}

int32_t main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }

    vector<int> landmarks = {1, n}; // you can choose more
    unordered_map<int, vector<int>> landmark_dists;

    for (int l : landmarks)
        landmark_dists[l] = dijkstra(l, adj, n);

    while (q--) {
        int a, b;
        cin >> a >> b;
        int best = INF;
        for (int l : landmarks) {
            best = min(best, landmark_dists[l][a] + landmark_dists[l][b]);
        }
        cout << (best >= INF ? -1 : best) << "\n";
    }
}
```

---

## 🔎 Key Takeaways

* Landmark-based precomputation is a space-time tradeoff
* Useful when queries are dense but graph is static
* Avoids full all-pairs Floyd-Warshall (which is `O(n^3)`)

---

## 📍 Task for You

* Try setting different landmarks and test how accuracy and speed change
* Add preprocessing time and compare it to naive per-query Dijkstra
* Try combinations of source landmarks and destination landmarks

---

Next up: **Module 6: 0-1 BFS — When Dijkstra is Overkill**
