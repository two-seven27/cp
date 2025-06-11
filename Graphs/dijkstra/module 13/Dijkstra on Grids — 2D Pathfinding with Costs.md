# 🧭 Module 13: Dijkstra on Grids — 2D Pathfinding with Costs

## 💪 Goal

Use Dijkstra’s algorithm to find shortest paths in **2D grids** with **non-uniform movement cost**.

* Common in pathfinding (games, robotics)
* Grid cells have cost, obstacles, and directions

---

## 📅 Problem Statement

Given a `n x m` grid:

* Each cell `(i, j)` has a cost to enter

* Some cells may be blocked

* Move in 4 directions (or 8 with diagonals)

* Find shortest path from `(sx, sy)` to `(ex, ey)`

* Practice Link: [CSES - Grid Pathfinding](https://cses.fi/problemset/task/1625/), [AtCoder - Grid Shortest Path](https://atcoder.jp/contests/abc176/tasks/abc176_d)

---

## 🧠 Intuition & Explanation

Dijkstra on a grid is like classic BFS, but with **weighted edges**.

### Grid as a Graph

* Nodes = cells `(i, j)`
* Edges = allowed moves (up/down/left/right)
* Edge weight = cost to enter the neighbor cell

### Use Min-Heap for Dijkstra

* Keep a `dist[i][j]` array
* Always process the cell with the smallest cost first

---

## ⚙️ Code Template

```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int32_t main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> grid[i][j]; // cost to enter cell

    vector<vector<int>> dist(n, vector<int>(m, INF));
    priority_queue<pair<int, pair<int, int>>, vector<>, greater<>> pq;

    dist[0][0] = grid[0][0];
    pq.push({grid[0][0], {0, 0}});

    while (!pq.empty()) {
        auto [d, cell] = pq.top(); pq.pop();
        int x = cell.first, y = cell.second;
        if (d > dist[x][y]) continue;

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            int new_dist = dist[x][y] + grid[nx][ny];
            if (new_dist < dist[nx][ny]) {
                dist[nx][ny] = new_dist;
                pq.push({new_dist, {nx, ny}});
            }
        }
    }

    cout << dist[n - 1][m - 1] << '\n';
}
```

---

## 🔎 Key Takeaways

* Dijkstra works beautifully in grids with variable cell costs
* Instead of nodes, treat each grid cell as a node
* Be careful with movement constraints (walls, directions)
* Time Complexity: `O(n * m * log(n * m))`

---

## 📍 Task for You

* Add diagonal moves
* Add teleport/portals between cells with extra cost
* Try changing costs based on terrain types

---

Next up: **Module 14: Dijkstra + A\* (A-Star) Heuristic Search**
