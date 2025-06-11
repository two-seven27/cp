# ⏰ Module 7: Dial’s Algorithm — Small Integer Weights Optimization

## 💪 Goal

Optimize shortest path computation when edge weights are small **positive integers** (e.g., between `0` and `K`).

---

## 📅 Problem Statement

Given a graph with `n` nodes and `m` edges, each edge has a non-negative weight `w ≤ K`, where `K` is small (e.g., 10").
Find the shortest path from node `1` to all other nodes efficiently.

* Practice Link: [CSES - Flight Discount](https://cses.fi/problemset/task/1195) (for concept, though has negative discount — not a fit for Dial, but helps see contrast)
* Better suited for custom graphs or grids where weights are from `1` to `K`

---

## 🧠 Intuition & Explanation

Dial’s Algorithm is a variant of Dijkstra that works in **O(K·(n + m))** time when all weights are integers in the range `[0, K]`.

### 🔧 Data Structure: Bucket Queue

* Instead of a priority queue, use `K+1` buckets (like mod-K hashing)
* Each bucket holds all nodes at a particular distance modulo `K+1`
* We process distances in increasing order

### 🔄 Logic

* Put source node `1` in bucket `0`
* While buckets are non-empty:

  * Get node `u` with current smallest distance
  * Relax its neighbors: move them to appropriate bucket

---

## ⚙️ Code (Simplified Dial’s Algorithm)

```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int K = 10; // Max weight

int32_t main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w; // 1 <= w <= K
        adj[u].emplace_back(v, w);
    }

    vector<int> dist(n + 1, INF);
    vector<deque<int>> buckets(K * n + 1);

    dist[1] = 0;
    buckets[0].push_back(1);
    int idx = 0;

    while (true) {
        while (idx < K * n && buckets[idx].empty()) ++idx;
        if (idx == K * n) break;

        int u = buckets[idx].front();
        buckets[idx].pop_front();

        if (dist[u] < idx) continue;

        for (auto &[v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                buckets[dist[v]].push_back(v);
            }
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << dist[i] << ' ';
    cout << '\n';
}
```

---

## 🔎 Key Takeaways

* Use Dial’s algorithm only when all edge weights are small integers
* Avoids expensive `log n` from Dijkstra’s priority queue
* Time Complexity: **O(K·(n + m))**

---

## 📍 Task for You

* Try building a graph with edge weights 1–10 and compare Dial’s vs Dijkstra
* Dial’s is especially fast on dense graphs with small weights
* Avoid if weights are large or negative

---

Next up: **Module 8: Dijkstra with Heuristics — A* Algorithm*\*
