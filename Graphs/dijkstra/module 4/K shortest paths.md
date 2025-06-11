# 🔁 Module 4: K Shortest Paths using Modified Dijkstra

## 💪 Goal

Find the **K shortest paths** from source node `1` to target node `n`, where:

* Paths may share nodes or edges
* Each path must be strictly greater in cost or different in structure

---

## 📅 Problem Statement

You are given a directed graph with `n` nodes and `m` edges. Find the **k shortest paths** from node `1` to node `n`.

* The paths are sorted by total weight.

* Multiple paths can have same weight but must differ in structure.

* Practice Link: [CSES - K Shortest Paths](https://cses.fi/problemset/task/1196)

---

## 🧠 Intuition & Explanation

Dijkstra is great for *one* shortest path. But to get K shortest paths:

* Every time we reach a node, we might reach it again via another route.
* Unlike standard Dijkstra, we can't mark nodes as "visited" after one pop.

### 🔑 Key Idea:

Use **Dijkstra-like algorithm** but allow visiting each node up to `k` times.

* Maintain a **min-heap** and a vector `dist[v]` that stores up to `k` distances for each node.
* Every time we reach node `v`, check if we've already found `k` paths. If not, store it and continue.
* When you reach `node n` for the `k`th time, you've found all answers.

---

## ⚙️ Code to Compute K Shortest Paths

```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<vector<int>> dist(n + 1);
    pq.emplace(0, 1);

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (dist[u].size() >= k) continue;
        dist[u].push_back(d);

        for (auto &[v, w] : adj[u]) {
            pq.emplace(d + w, v);
        }
    }

    for (int x : dist[n]) cout << x << " ";
    cout << "\n";
}
```

---

## ✅ Why This Works

* We allow revisiting nodes to find more than one path
* The priority queue ensures smaller-cost paths are processed first
* Only store the first `k` unique costs per node

---

## 📊 Complexity

* Time: `O(k * (n + m) * log n)` in worst case
* Space: `O(k * n)` for `dist[]` storage

---

## 🔎 Key Takeaways

* Standard Dijkstra marks a node done after 1 pop — not sufficient here
* For K-path problems, revisit nodes up to `k` times
* Great for variations involving constraints like "find top K solutions"

---

## 📍 Task for You

* Try graphs with many equally short paths
* Change `k` and observe how output changes
* Compare this to Yen’s Algorithm (more advanced, slower but works for simple paths)

---

Next up: **Module 5: Dijkstra for All-Pairs K Shortest Paths (or Landmarks)**
