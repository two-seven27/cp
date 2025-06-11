# 🔁 Module 11: K Shortest Paths — Yen’s Algorithm & Variants

## 💪 Goal

Find not just the **shortest path**, but the **K shortest simple paths** from a source `s` to destination `t`.

* All paths must be **simple** (no repeated nodes)
* Useful for network routing, planning, backups, etc.

---

## 📅 Problem Statement

Given a directed graph with `n` nodes and `m` edges, a source node `s` and a destination `t`, find the **k shortest simple paths** from `s` to `t`.

* Edges have non-negative weights

* Paths must not revisit nodes

* Practice Link: [SPOJ - KSHORT](https://www.spoj.com/problems/KSHORT/) or [K Shortest Paths - Hackerearth](https://www.hackerearth.com/problem/algorithm/k-shortest-paths-5/)

---

## 🧠 Intuition & Explanation

Finding the shortest path is Dijkstra’s job. But for **2nd shortest, 3rd shortest**, we need something more advanced.

### 💡 Yen’s Algorithm

1. Use Dijkstra to find the **shortest path**
2. For `i` from `2` to `k`, generate new candidates by **removing one edge** from each path prefix and recomputing the path
3. Store all candidates in a **min-heap** based on total cost
4. Keep extracting the next shortest unique path

This ensures all paths are:

* Simple (no cycles)
* In increasing order of total weight

---

## ⚙️ Conceptual Code Structure

```text
- A[] = shortest paths found so far (initially with Dijkstra)
- B = min-heap of candidate paths

For i = 2 to k:
    For j = 0 to len(path_i - 1):
        Spur = path[0..j]
        Root = path[j+1..end]

        Temporarily remove edges from previous paths that share the same prefix
        Run Dijkstra from spur node to t

        If path found:
            Combine spur + new path => candidate
            Add to B

    Extract minimum from B, add to A
```

---

## 🧠 Variants

* **Eppstein’s Algorithm**: Handles repeated nodes, works for general K shortest paths faster
* **Modified BFS/DFS** for small graphs or unweighted cases
* **A\* + heap-based** variants

---

## 🔎 Key Takeaways

* Yen’s Algorithm = repeated Dijkstra with edge manipulations
* Time Complexity: `O(k * n * log n)` if Dijkstra is optimized
* Keeps all paths **simple** and **ordered**

---

## 📍 Task for You

* Implement for small graphs (<= 100 nodes)
* Visualize paths: highlight how changing spur affects result
* Think of real use-cases: multiple alternate route planning, bandwidth fallback, etc.

---

Next up: **Module 12: Dynamic Dijkstra — Update Edge Weights Efficiently**
