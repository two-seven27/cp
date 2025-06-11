# ✅ Module 1: Standard Dijkstra Refresher

## 💪 Goal

Implement classic Dijkstra’s algorithm:

* Find shortest distances from a source node to all other nodes
* Works with non-negative edge weights only

---

## 📅 Problem Statement

Given a directed weighted graph with `n` nodes and `m` edges, find the shortest distances from node `1` to all other nodes.

### Input Format:

```
n m
u1 v1 w1
u2 v2 w2
...
um vm wm
```

1-based indexing.

### Sample Input:

```
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
```

### Expected Output:

```
0 2 3 9 6
```

---

## ⚙️ Code Template

```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        // For undirected: adj[v].emplace_back(u, w);
    }

    vector<int> dist(n + 1, INF);
    dist[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, 1); // {distance, node}

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

    for (int i = 1; i <= n; ++i)
        cout << (dist[i] == INF ? -1 : dist[i]) << " ";
    cout << "\n";
}
```

---

## 🧠 Key Concepts

* Dijkstra works with non-negative edge weights
* Uses a **min-priority queue** to always expand the shortest available path
* Greedy + Relaxation based

---

## 📍 Tasks for You

* Run on sample input
* Modify to undirected by uncommenting `adj[v]...`
* Try reversing edges and running from node `n` to get distances to node 1

---

Next up: **Module 2: Path Counting Variant** → `ways[]`
