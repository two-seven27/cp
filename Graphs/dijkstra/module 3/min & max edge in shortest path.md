# 🚦 Module 3: Track Min and Max Edges in Shortest Paths

## 💪 Goal

Along with shortest path distance and number of paths, also compute:

* Minimum number of edges used in any shortest path
* Maximum number of edges used in any shortest path

---

## 📅 Problem Statement

Given a directed graph with `n` nodes and `m` edges, and all edge weights ≥ 0, compute:

* Shortest distance from node 1 to node n

* Number of such paths

* Minimum and maximum number of edges in any shortest path from 1 to n

* Practice Link: [CSES - Investigation](https://cses.fi/problemset/task/1202)

---

## 🧠 Intuition & Explanation

Standard Dijkstra gives shortest distance, and in Module 2 we added `ways[]` to count paths.
Now we go a step further:

* Track `min_flight[v]` = min number of edges used to reach node `v`
* Track `max_flight[v]` = max number of edges used to reach node `v`

### When relaxing an edge (u → v with weight w):

* If a **shorter path is found**:

  * Update `dist[v]`, `ways[v] = ways[u]`
  * Set `min_flight[v] = min_flight[u] + 1`
  * Set `max_flight[v] = max_flight[u] + 1`

* If an **equal path is found**:

  * Add to `ways[v]`
  * Update `min_flight[v] = min(min_flight[v], min_flight[u] + 1)`
  * Update `max_flight[v] = max(max_flight[v], max_flight[u] + 1)`

This naturally fits into Dijkstra’s order, where `dist[u]` is already finalized or optimal.

---

## ⚙️ Dijkstra Code with Edge Tracking

```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int MOD = 1e9 + 7;

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
    }

    vector<int> dist(n + 1, INF), ways(n + 1, 0);
    vector<int> min_flight(n + 1, INF), max_flight(n + 1, -INF);

    dist[1] = 0;
    ways[1] = 1;
    min_flight[1] = 0;
    max_flight[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, 1);

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto &[v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                ways[v] = ways[u];
                min_flight[v] = min_flight[u] + 1;
                max_flight[v] = max_flight[u] + 1;
                pq.emplace(dist[v], v);
            } else if (dist[v] == dist[u] + w) {
                ways[v] = (ways[v] + ways[u]) % MOD;
                min_flight[v] = min(min_flight[v], min_flight[u] + 1);
                max_flight[v] = max(max_flight[v], max_flight[u] + 1);
            }
        }
    }

    cout << dist[n] << " " << ways[n] << " " << min_flight[n] << " " << max_flight[n] << "\n";
}
```

---

## 🔎 Key Takeaways

* Extend Dijkstra by tracking additional attributes: `min_flight[]`, `max_flight[]`
* Use conditional logic during relaxation to update edge counts
* This is powerful in questions involving constraints on path length

---

## 📍 Task for You

* Reuse earlier input and validate min/max edge values
* Create graphs with multiple shortest paths that vary in edge count
* Modify the graph to experiment with edge weights that create tie scenarios

---

Next up: **Module 4: K Shortest Paths using Modified Dijkstra**
}
