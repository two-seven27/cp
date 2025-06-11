# 🧩 Module 4: Path Recovery — Reconstructing the Shortest Path

## 💪 Goal

Given a graph, not only find the shortest distance from source to destination, but also **print the actual path** taken.

---

## 📝 Problem Statement

Given a directed/undirected weighted graph with `n` nodes and `m` edges, and a source node `s`, compute the shortest path to node `t`, and **reconstruct the path**.

* 📅 Practice Link: [CSES - Shortest Routes I](https://cses.fi/problemset/task/1671)
* 📅 Practice Link: [CSES - Shortest Routes II (All-Pairs)](https://cses.fi/problemset/task/1672)

---

## 🧐 Intuition & Explanation

Standard Dijkstra only gives you the shortest distances.
To reconstruct the path:

* Track a `parent[]` array.
* When relaxing edge `u → v`, do:

  ```cpp
  if (dist[v] > dist[u] + w) {
      dist[v] = dist[u] + w;
      parent[v] = u;
  }
  ```
* Once Dijkstra finishes, backtrack from destination `t` to `s` using the `parent[]` array.

### 🔍 Visualization

If shortest path from 1 to 5 is:

```
1 → 2 → 4 → 5
```

Then:

```cpp
parent[5] = 4
parent[4] = 2
parent[2] = 1
```

So you reverse it at the end to get path from source to destination.

---

## ⚙️ Code Template (Path Recovery with Dijkstra)

```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

int32_t main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }

    vector<int> dist(n + 1, INF), parent(n + 1, -1);
    dist[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, 1);

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto &[v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.emplace(dist[v], v);
            }
        }
    }

    if (dist[n] == INF) {
        cout << "No path!\n";
        return 0;
    }

    vector<int> path;
    for (int cur = n; cur != -1; cur = parent[cur])
        path.push_back(cur);
    reverse(path.begin(), path.end());

    for (int node : path) cout << node << ' ';
    cout << '\n';
}
```

---

## 🔹 Key Takeaways

* Use a `parent[]` array to track which node leads to the current node in the shortest path.
* Backtrack from destination using `parent[]` to recover path.
* Reconstructing path is `O(n)` after Dijkstra.

---

## 📁 Practice Tasks

* 🔹 CSES: [Shortest Routes I](https://cses.fi/problemset/task/1671)
* 🔹 AtCoder Beginner: Dijkstra 1 [ABC 191 E](https://atcoder.jp/contests/abc191/tasks/abc191_e)

---

Next up: **Module 5: 0-1 BFS for Binary Weighted Graphs**
