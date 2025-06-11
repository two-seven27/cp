# 📊 Module 2: Path Counting with Dijkstra

## 💪 Goal

Extend Dijkstra to count **number of shortest paths** from source node (1) to all other nodes.

* Result modulo $10^9 + 7$
* Modify standard Dijkstra to track multiple shortest paths

---

## 📅 Problem Statement

Given a directed weighted graph with `n` nodes and `m` edges, count the number of distinct shortest paths from node `1` to node `n`.

* Practice Link: [CSES - Investigation](https://cses.fi/problemset/task/1202)

### Input Format:

```
n m
u1 v1 w1
u2 v2 w2
...
um vm wm
```

### Sample Input:

```
4 5
1 2 3
1 3 2
3 2 1
1 4 5
2 4 1
```

### Expected Output:

```
Shortest distance to node 4: 5
Number of shortest paths: 2
```

---

## 🧠 Intuition & Explanation

In standard Dijkstra's algorithm, we only compute the shortest distances. But often in competitive programming, we are also asked to count **how many different ways** we can reach a node using the shortest distance.

So how do we do that?

* Let `ways[v]` = number of shortest paths from node `1` to node `v`
* When you find a **shorter path**, reset `ways[v] = ways[u]`
* When you find **another path of equal length**, do `ways[v] += ways[u]`

This builds on the core Dijkstra idea: when you reach a node `v` with the shortest distance, you check if other paths can also lead to `v` with the same cost. If yes, count them!

### ✅ Why This Works:

* Dijkstra explores nodes in increasing order of distance
* So when we relax an edge and find `dist[v] == dist[u] + w`, we already know `dist[u]` is finalized or optimal
* We can safely say that every such `u` contributes `ways[u]` new shortest paths to `v`

---

## ⚙️ Modified Dijkstra Code

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
    dist[1] = 0;
    ways[1] = 1;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, 1);

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto &[v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                ways[v] = ways[u];
                pq.emplace(dist[v], v);
            } else if (dist[v] == dist[u] + w) {
                ways[v] = (ways[v] + ways[u]) % MOD;
            }
        }
    }

    cout << "Shortest distance to node " << n << ": " << dist[n] << "\n";
    cout << "Number of shortest paths: " << ways[n] << "\n";
}
```

---

## 🔎 Key Takeaways

* Extend Dijkstra with `ways[]` to count shortest paths
* Use modulo $10^9 + 7$ for large outputs
* Logic fits well into Dijkstra because of greedy + relaxed structure

---

## 📍 Task for You

* Run the code on sample input
* Create your own graphs with multiple shortest paths and validate correctness
* Try modifying graph directionality or weights to explore edge cases

---

Next up: **Module 3: Track Min and Max Edges in Shortest Paths**
