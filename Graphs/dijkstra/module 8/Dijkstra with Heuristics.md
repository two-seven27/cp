# ⭐ Module 8: A\* (A-Star) Algorithm — Dijkstra with Heuristics

## 💪 Goal

Speed up shortest path search when the target node is known in advance.
Especially useful in 2D grids, maps, or any setting where a good **heuristic** exists.

---

## 📅 Problem Statement

Given a graph or grid and a source node `s` and destination `t`, find the shortest path from `s` to `t`.

You can assume the graph allows estimation of how far a node is from the goal (a heuristic `h(v)`).

* Practice Link: [No direct CSES problem — good to try on grid pathfinding or simulate](https://www.geeksforgeeks.org/a-search-algorithm/) on your own

---

## 🧠 Intuition & Explanation

A\* is like Dijkstra, but it prioritizes nodes that seem closer to the destination — it uses a **heuristic** `h(v)` to guide the search.

### 🔑 Key Idea:

* In Dijkstra: `priority = dist[v]`
* In A\*: `priority = dist[v] + h(v)`

  * `h(v)` is an estimate of cost from `v` to destination
  * Must be **admissible** (i.e., it should not overestimate the actual cost)

In grid-based problems, a common heuristic is **Manhattan distance**:

```
h(v) = abs(v.x - goal.x) + abs(v.y - goal.y)
```

---

## ⚙️ Code (A\* on a 2D Grid)

```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

struct Node {
    int x, y, cost, fscore;
    bool operator>(const Node& other) const {
        return fscore > other.fscore;
    }
};

int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2); // Manhattan
}

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int32_t main() {
    int n, m;
    cin >> n >> m; // grid size
    vector<string> grid(n);
    for (auto &row : grid) cin >> row;

    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;

    vector<vector<int>> dist(n, vector<int>(m, INF));
    priority_queue<Node, vector<Node>, greater<>> pq;

    dist[sx][sy] = 0;
    pq.push({sx, sy, 0, heuristic(sx, sy, ex, ey)});

    while (!pq.empty()) {
        auto [x, y, cost, fscore] = pq.top(); pq.pop();
        if (x == ex && y == ey) {
            cout << cost << '\n';
            return 0;
        }
        if (cost > dist[x][y]) continue;

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] == '#') continue;
            if (dist[nx][ny] > dist[x][y] + 1) {
                dist[nx][ny] = dist[x][y] + 1;
                int f = dist[nx][ny] + heuristic(nx, ny, ex, ey);
                pq.push({nx, ny, dist[nx][ny], f});
            }
        }
    }
    cout << -1 << '\n'; // no path
}
```

---

## 🔎 Key Takeaways

* A\* is optimal and complete if heuristic `h(v)` is admissible
* Prioritizes nodes closer to destination: **greedy + safe**
* Especially efficient for pathfinding in grids or geometric problems

---

## 📍 Task for You

* Try comparing A\* and Dijkstra on grids
* Experiment with different heuristics (Euclidean, Chebyshev, etc.)
* A\* is used in games, robotics, maps — understand its strength!

---

Next up: **Module 9: Johnson’s Algorithm — All-Pairs on Sparse Graphs**
