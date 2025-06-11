# 📊 Module 7: Extra State Dijkstra — State-Enhanced Pathfinding

## 💪 Goal

Learn how to modify Dijkstra when each node carries additional information (like fuel left, number of coupons used, teleport chance, etc).

---

## 📝 Problem Statement

Given a graph where moving through an edge may depend not only on the node but also on an extra state (e.g., discount coupon left), compute shortest distances from the start.

* 📅 Practice Link: [CSES - Flight Discount](https://cses.fi/problemset/task/1195/)
* 📅 Practice Link: [CSES - Planets and Kingdoms](https://cses.fi/problemset/task/1682/) (conceptual for SCC + extra state transitions)

---

## 🧐 Intuition & Explanation

Normally, Dijkstra works on a 1D distance array: `dist[node]`. But when **extra constraints or powers** exist (e.g., use one discount coupon), we extend it to `dist[node][state]`.

### 🔍 Example

Suppose we have one discount coupon:

* You can use it **once** to make a flight free (cost 0)
* Or not use it, and pay full price.

We need to track:

* `dist[node][0]` ⇒ reached node without using coupon
* `dist[node][1]` ⇒ reached node after using coupon

---

## ⚙️ Code Template (Flight Discount Variant)

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

    vector<vector<int>> dist(n + 1, vector<int>(2, INF));
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;

    dist[1][0] = 0;
    pq.push({0, 1, 0}); // cost, node, used_discount?

    while (!pq.empty()) {
        auto [d, u, used] = pq.top(); pq.pop();
        if (d > dist[u][used]) continue;

        for (auto &[v, w] : adj[u]) {
            // Case 1: Move without using discount
            if (dist[v][used] > d + w) {
                dist[v][used] = d + w;
                pq.push({dist[v][used], v, used});
            }
            // Case 2: Use discount if not used yet
            if (!used && dist[v][1] > d) {
                dist[v][1] = d;
                pq.push({dist[v][1], v, 1});
            }
        }
    }

    cout << min(dist[n][0], dist[n][1]) << '\n';
}
```

---

## 🔹 Key Takeaways

* `dist[node][state]` allows tracking extra powers/conditions
* Use a 3D tuple in priority queue: `{cost, node, state}`
* Time Complexity: `O(n * states * log(n))`

---

## 📁 Practice Tasks

* 🔹 [CSES - Flight Discount](https://cses.fi/problemset/task/1195/)
* 🔹 [Codeforces - Mr. Kitayuta's Gift](https://codeforces.com/contest/505/problem/B)
* 🔹 [Kattis - Fuel Tank](https://open.kattis.com/problems/fueltank)

---

Next up: **Module 8: Dijkstra on Grid — Graphs with Spatial Structure**
