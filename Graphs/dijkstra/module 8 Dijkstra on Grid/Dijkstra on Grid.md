# 🧱 Module 8: Dijkstra on Grid — Pathfinding in 2D Space

## 💪 Goal

Apply Dijkstra’s algorithm to **2D grids** where each cell has a movement cost.

---

## 📅 Problem Statement

Given an `n x m` grid where each cell contains a cost, find the minimum total cost to move from the **top-left** to the **bottom-right**.

You can move in 4 directions (up, down, left, right).

* Practice Link: [CSES - Grid Paths](https://cses.fi/problemset/task/1625) (easier path counting)
* Practice Link: [CSES - Grid Weighted](https://cses.fi/problemset/task/1629) (**actual Dijkstra variant**)

---

## 🧠 Intuition & Explanation

You can treat every cell `(i, j)` as a node in the graph.

* Moving to neighbor cells is like adding edges.
* Edge weights are the cost of entering the next cell.

We use **Dijkstra** because costs are non-negative.

### 🔑 State = Cell Position

* Instead of `dist[node]`, now you maintain `dist[i][j]`
* You use a priority queue to process cells by minimum cost so far.

---

## ⚙️ Code Template (Dijkstra on Grid)

```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

int32_t main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> grid[i][j];

    vector<vector<int>> dist(n, vector<int>(m, INF));
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;

    dist[0][0] = grid[0][0];
    pq.push({dist[0][0], 0, 0});

    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

    while (!pq.empty()) {
        auto [cost, x, y] = pq.top(); pq.pop();
        if (cost > dist[x][y]) continue;

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                int new_cost = cost + grid[nx][ny];
                if (dist[nx][ny] > new_cost) {
                    dist[nx][ny] = new_cost;
                    pq.push({new_cost, nx, ny});
                }
            }
        }
    }

    cout << dist[n-1][m-1] << '\n';
}
```

---

## 🔎 Key Takeaways

* Dijkstra works perfectly on grid if you treat each cell as a node
* Movement directions are edges
* Use `{cost, x, y}` in the priority queue

Time complexity: `O(n * m * log(n * m))`

---

## 📍 Practice Problems

* [CSES - Grid Weighted](https://cses.fi/problemset/task/1629)
* [Leetcode 1631 - Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort/)
* [Kattis - Minimum Cost Path](https://open.kattis.com/problems/minimumcostpath)

---

Next: **Module 9: Time-Dependent Dijkstra — Arrival-Based Edge Costs**
