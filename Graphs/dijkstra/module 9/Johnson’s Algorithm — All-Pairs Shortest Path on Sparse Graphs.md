# 🧠 Module 9: Johnson’s Algorithm — All-Pairs Shortest Path on Sparse Graphs

## 💪 Goal

Efficiently find shortest paths between **all pairs of nodes** in a **sparse graph** with **negative edge weights**, but **no negative cycles**.

---

## 📅 Problem Statement

Given a directed graph with `n` nodes and `m` edges (some with negative weights), find the shortest path from every node `u` to every node `v`. The graph has **no negative weight cycles**.

* Suitable for sparse graphs: `m ≈ O(n)`

* Handles negative weights (unlike Dijkstra)

* Faster than Floyd-Warshall on sparse graphs

* Practice Link: [No exact CSES problem — try on custom graphs or see SPOJ/GeeksforGeeks](https://www.geeksforgeeks.org/johnsons-algorithm/)

---

## 🧠 Intuition & Explanation

Dijkstra fails on negative weights. Bellman-Ford works but is `O(n·m)` for one source.
We need **All-Pairs Shortest Paths (APSP)** with:

* Negative weights ✅
* No negative cycles ❌
* Better than `O(n³)` of Floyd-Warshall ✅

### 🧩 Trick: Reweight the graph using Bellman-Ford!

1. Add a dummy node `0` and connect it to all nodes with edge weight `0`
2. Run Bellman-Ford from node `0` to get `h(v)` for each node `v`
3. For every edge `(u → v)` with weight `w`, reweight it:

   ```
   w' = w + h[u] - h[v]
   ```

   These new weights are **non-negative**
4. Now run **Dijkstra** from every node on the reweighted graph
5. Recover true distances:

   ```
   dist[u][v] = dijkstra_result[u][v] + h[v] - h[u]
   ```

---

## ⚙️ Pseudocode Summary

```cpp
// Step 1: Add dummy node 0 to all others with weight 0
// Step 2: Bellman-Ford from node 0 to get h[]
// Step 3: Reweight edges
// Step 4: For each node, run Dijkstra
// Step 5: Adjust distances back using h[v] - h[u]
```

---

## 🔎 Key Takeaways

* Handles **negative weights**, not negative cycles
* Faster than Floyd-Warshall if graph is sparse
* Uses **Bellman-Ford + Dijkstra** combination smartly
* Final complexity: **O(n·(m + n·logn))**

---

## 📍 Task for You

* Implement Johnson’s on your own test graph
* Compare it with Floyd-Warshall and see time difference
* Think why reweighting works (hint: triangle inequality is preserved!)

---

Next up: **Module 10: Bitmask Dijkstra — DP + Shortest Path Combo**
