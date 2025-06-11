
# 📊 Module 6: Multi-Source Dijkstra — Many Start Nodes, One Algorithm

## 💪 Goal

Extend Dijkstra's Algorithm to work from **multiple sources** simultaneously. Useful in problems like finding the closest hospital, fire station, or service.

---

## 📝 Problem Statement

Given a graph with `n` nodes and `m` edges, and a set of `k` source nodes, find the shortest distance from **any of the source nodes** to every other node.

* 📅 Practice Link: [CSES - Monsters](https://cses.fi/problemset/task/1194/) (first phase is multi-source BFS, but extended problems may use Dijkstra)
* 📅 Practice Link: [CSES - Police Chase](https://cses.fi/problemset/task/1695/) (multi-source shortest path)

---

## 🧐 Intuition & Explanation

Imagine multiple source nodes all pushing their distance outward in parallel. The trick is to:

* Initialize all source nodes in the priority queue with `dist = 0`
* Push them into the queue **before** starting Dijkstra
* Run Dijkstra as usual

### 🔍 Core Insight

Instead of running Dijkstra `k` times, we run **one** Dijkstra with all `k` starting points in the queue initially. The queue automatically ensures shortest paths are picked greedily.

---

## ⚙️ Code Template (Multi-Source Dijkstra)

```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

int32_t main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> sources(k);
    for (int &x : sources) cin >> x;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w); // if undirected
    }

    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    for (int src : sources) {
        dist[src] = 0;
        pq.emplace(0, src);
    }

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
        cout << dist[i] << ' ';
    cout << '\n';
}
```

---

## 🔹 Key Takeaways

* Add all `k` sources into the priority queue with distance `0`
* Dijkstra automatically handles expansion from multiple points
* Time complexity: **O((n + m) log n)**, same as regular Dijkstra

---

## 📁 Practice Tasks

* 🔹 [CSES - Police Chase](https://cses.fi/problemset/task/1695/)
* 🔹 [Kickstart - Rabbit House](https://codingcompetitions.withgoogle.com/kickstart/round/0000000000436140/problems) (similar intuition)

---

Next up: **Module 7: Extra State Dijkstra — State-Enhanced Pathfinding (e.g., fuel, coupons, etc)**
