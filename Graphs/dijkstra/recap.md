# 🚀 Dijkstra Variants: Final Recap & Revision Worksheet

## ✅ Summary of All 9 Modules

| Module | Topic                   | Key Idea                                  | DS Used          | Time Complexity         |
| ------ | ----------------------- | ----------------------------------------- | ---------------- | ----------------------- |
| 1      | Standard Dijkstra       | Priority queue, dist\[]                   | `priority_queue` | `O((N + M) log N)`      |
| 2      | Path Counting           | Track `ways[]` alongside `dist[]`         | `ways[]` array   | `O((N + M) log N)`      |
| 3      | Min/Max Edges           | Track `min_edges[]`, `max_edges[]`        | `dist[]` arrays  | `O((N + M) log N)`      |
| 4      | Path Recovery           | Store `parent[]` to reconstruct path      | `parent[]`       | `O(N)` (after Dijkstra) |
| 5      | 0-1 BFS                 | Use deque for 0/1 weights                 | `deque`          | `O(N + M)`              |
| 6      | Multi-Source Dijkstra   | Push all sources with dist = 0            | `priority_queue` | `O((N + M) log N)`      |
| 7      | Extra State Dijkstra    | State becomes `(node, feature)`           | `dist[node][k]`  | `O(N*K log N)`          |
| 8      | Dijkstra on Grid        | Treat grid as graph, move in 4 directions | `priority_queue` | `O(N*M log(N*M))`       |
| 9      | Time-Dependent Dijkstra | Edge weight depends on arrival time       | `priority_queue` | Custom, varies          |

---

## 📘 Common Dijkstra Pitfalls

* Forgetting to skip old entries: `if (d > dist[u]) continue;`
* Not updating all parallel state arrays (`ways[]`, `min[]`, etc.)
* Not handling equal distances properly when counting paths
* Overusing Dijkstra when 0-1 BFS suffices

---

## 📝 Worksheet Questions

### Module 1-3: Foundation

1. Implement Dijkstra on a weighted undirected graph.
2. Extend it to count paths (`ways[]`) from node 1 to all others.
3. Modify to find minimum and maximum number of edges in shortest paths.

### Module 4: Path Recovery

4. Implement `parent[]` tracking and reconstruct the path from node 1 to `n`.

### Module 5: 0-1 BFS

5. Given a graph with weights `0/1`, use a deque to compute shortest distances.
6. Compare with priority queue on same graph — what’s faster?

### Module 6: Multi-Source Dijkstra

7. Given multiple start points, modify Dijkstra to compute minimum distances from any source.
8. Apply this to problems like spreading fire or rumor.

### Module 7: Extra State

9. Solve a problem where you can use a teleport only once. Model as `dist[node][usedTeleport]`.
10. Apply similar logic to fuel or coupons.

### Module 8: Grid

11. Compute minimum cost to reach bottom-right in an `n x m` grid with weights.
12. Extend to allow diagonal moves (8 directions).

### Module 9: Time-Dependent

13. Implement Dijkstra where edge usage depends on arrival time.
14. Apply to train schedules: each edge has (start time, interval, duration).

---

## 🧠 Bonus Challenges

* Dial’s Algorithm: Works in `O(N + C)` when edge weights ≤ C
* A\* Search: Heuristic version of Dijkstra, useful for 2D paths
* Dijkstra with persistent data: Immutable states for multi-query systems

---

## 🧩 Tips for Practice

* Track what variant a problem is testing
* Reuse templates you built in earlier modules
* Start from simple and build toward edge cases

---

Let me know if you'd like a **cheatsheet image**, **PDF export**, or a **set of contests/problems** to reinforce these modules! ✨
