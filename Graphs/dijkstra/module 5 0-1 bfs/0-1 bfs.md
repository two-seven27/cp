# 🧮 Module 6: 0-1 BFS — Efficient Shortest Path for Binary Weights

## 💪 Goal

Optimize shortest path computation when edge weights are only **0 or 1**. Standard Dijkstra is overkill.

---

## 📅 Problem Statement

Given a directed graph with `n` nodes and `m` edges where each edge has a weight **either 0 or 1**, compute shortest distances from node `1` to all other nodes.

* Practice Link: [CSES - High Score](https://cses.fi/problemset/task/1162) (binary edge weight version)

---

## 🧠 Intuition & Explanation

Standard Dijkstra uses a priority queue (`O(log n)` per operation). But with **edge weights 0 or 1**, we can do better using a **deque**!

### 🔑 Key Idea: BFS-like approach

* Use a deque (`std::deque`) instead of a priority queue
* If the edge has **weight 0**, push it to the **front** (like BFS — same level)
* If the edge has **weight 1**, push it to the **back** (like next level in BFS)

This ensures we always explore the shortest cost node first — just like Dijkstra, but in **`O(n + m)` time**!

---

## ⚙️ Code for 0-1 BFS

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
        adj[u].emplace_back(v, w); // w = 0 or 1
    }

    vector<int> dist(n + 1, INF);
    dist[1] = 0;
    deque<int> dq;
    dq.push_back(1);

    while (!dq.empty()) {
        int u = dq.front(); dq.pop_front();
        for (auto &[v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (w == 0) dq.push_front(v);
                else dq.push_back(v);
            }
        }
    }

    for (int i = 1; i <= n; ++i) cout << dist[i] << ' ';
    cout << '\n';
}
```

---

## 🔎 Key Takeaways

* 0-1 BFS uses a deque instead of a priority queue
* Much faster than Dijkstra when weights are only 0 or 1
* Time Complexity: **O(n + m)**

---

## 📍 Task for You

* Try creating your own 0-1 graphs with mix of edges
* Compare timing with Dijkstra — see the difference
* Try turning undirected edges into 2 directed ones if needed

---

Next up: **Module 7: Dial’s Algorithm — Small Integer Edge Weights**
