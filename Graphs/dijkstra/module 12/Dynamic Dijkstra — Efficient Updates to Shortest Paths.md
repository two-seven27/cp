# 🔄 Module 12: Dynamic Dijkstra — Efficient Updates to Shortest Paths

## 💪 Goal

Handle **changing edge weights** (add/remove/update) while maintaining shortest paths.

* Real-time systems: traffic updates, routing, etc.
* Recomputing from scratch each time is slow

---

## 📅 Problem Statement

Given a graph and an initial source `s`, compute shortest distances to all nodes. Then, **after each update** (like edge weight change), efficiently recompute affected shortest paths.

* Practice Link: \[Dynamic Shortest Path — CF/USACO-style custom problems]

---

## 🧠 Intuition & Explanation

Standard Dijkstra is `O(m log n)` — too slow if you rerun it after every small change.

### 🔧 Use Case

* Edge `(u, v)` weight **decreases** → may create shorter paths
* Edge `(u, v)` weight **increases** → may invalidate current shortest path

We handle updates **selectively** using priority queues and edge relaxation.

---

## ⚙️ Update Strategies

### 1. **Decrease Edge Weight**

* Try relaxing just `(u → v)`
* If `dist[v] > dist[u] + new_w`, update and re-run Dijkstra **only from `v`**

### 2. **Increase Edge Weight**

* If current shortest path used `(u, v)`, the path might be invalid
* Recompute shortest paths **only for affected subtree**

---

## 🧰 Code Sketch

```cpp
void updateEdge(int u, int v, int new_w) {
    // Case: weight decreases
    if (new_w < edge[u][v]) {
        edge[u][v] = new_w;
        if (dist[v] > dist[u] + new_w) {
            dist[v] = dist[u] + new_w;
            pq.push({dist[v], v}); // Restart Dijkstra from v
        }
    }
    // Case: weight increases — recompute if edge was used
    else if (used_in_path[u][v]) {
        edge[u][v] = new_w;
        // Recompute affected nodes
        recomputeAffected();
    }
}
```

---

## 🧠 Alternatives

* Use **Dynamic Trees** (Link-Cut Trees) for fully dynamic updates
* **Lazy Dijkstra**: recompute only as needed when querying

---

## 🔎 Key Takeaways

* Don't rerun full Dijkstra — update **only affected nodes**
* Decrease → relax and push
* Increase → backtrack affected nodes
* Complexity: Depends on change locality, often sublinear in practice

---

## 📍 Task for You

* Simulate real-time graph changes and verify incremental updates
* Practice with multiple edge updates and query sequences

---

Next up: **Module 13: Dijkstra on Grids — Pathfinding in 2D Worlds**
