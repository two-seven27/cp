# 🧮 Module 10: Bitmask Dijkstra — Combining DP and Shortest Paths

## 💪 Goal

Solve pathfinding problems with **state constraints**, such as:

* Visit all nodes
* Visit a subset of nodes
* Keep track of visited nodes using **bitmasks**

---

## 📅 Problem Statement

Given a graph and a set of `k` important nodes, find the shortest path that **visits all `k` nodes exactly once** (Traveling Salesman variant).

* Graph is typically complete or small

* Use **bitmask DP + Dijkstra** to handle state explosion

* Practice Link: [CSES - Planets and Kingdoms](https://cses.fi/problemset/task/1682/) (related to connectivity + can be extended with states)

* \[TSP-like problems on AtCoder, SPOJ, or Codeforces]

---

## 🧠 Intuition & Explanation

Each state is:

```text
(state, current_node) = (bitmask of visited, position)
```

### 🔁 DP Transition

For all `mask` and all nodes `u`, try to go to an unvisited `v`:

```cpp
if (!(mask & (1 << v)))
    dp[mask | (1 << v)][v] = min(dp[mask | (1 << v)][v], dp[mask][u] + dist[u][v]);
```

This is often combined with Dijkstra to speed up transitions.

---

## ⚙️ Code Skeleton (TSP Variant)

```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

int32_t main() {
    int n; cin >> n;
    vector<vector<int>> dist(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> dist[i][j]; // input graph distances

    int full = (1 << n);
    vector<vector<int>> dp(full, vector<int>(n, INF));
    dp[1][0] = 0; // starting from node 0

    for (int mask = 1; mask < full; ++mask) {
        for (int u = 0; u < n; ++u) {
            if (!(mask & (1 << u))) continue;
            for (int v = 0; v < n; ++v) {
                if (mask & (1 << v)) continue;
                int next = mask | (1 << v);
                dp[next][v] = min(dp[next][v], dp[mask][u] + dist[u][v]);
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < n; ++i)
        ans = min(ans, dp[full - 1][i] + dist[i][0]);
    cout << ans << '\n';
}
```

---

## 🔎 Key Takeaways

* Use **bitmask** to track visited states (size `2^n`)
* Combine with Dijkstra if needed when transitions are sparse
* Classic for **TSP**, **set cover**, **subgraph visit** problems
* Time Complexity: `O(n^2 * 2^n)`

---

## 📍 Task for You

* Try reducing number of states (e.g., symmetrical properties)
* Practice TSP on small graphs (≤ 20 nodes)
* Think when to use Dijkstra + Bitmask (e.g., transitions with varying weights)

---

Next up: **Module 11: K Shortest Paths — Yen’s Algorithm and Variants**
