# 🕛 Module 9: Time-Dependent Dijkstra — Edges with Dynamic Costs

## 💪 Goal

Handle cases where edge weights **depend on the time** you arrive at the node, i.e., weights are **time-sensitive** (e.g., train schedules).

---

## 📅 Problem Statement

You're given a directed graph where each edge can only be used at specific times (e.g., every 3 minutes, or only after 5 PM). Compute the shortest time to reach the destination starting from node 1 at time 0.

* 🔹 Practice Link: [CSES - Time-Dependent Dijkstra (Train Timetable)](https://cses.fi/problemset/task/1202/)

---

## 🧐 Intuition & Explanation

In normal Dijkstra, cost to move through an edge is **fixed**. But what if:

* A train runs every `k` minutes?
* You must **wait** before you can take the next edge?

Then, you must model your time **as part of the state** and update your logic accordingly.

### 🔍 Key Concept

If you arrive at node `u` at time `t`, and want to take an edge that runs every `k` minutes starting at time `s` with duration `d`, the next possible departure time is:

```cpp
departure = max(t, s)
if (departure % k != 0)
    departure += k - (departure % k);
```

Arrival time at `v` = `departure + d`

---

## ⚙️ Code Template

```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

struct Edge {
    int to, s, d, t; // destination, start time, interval, travel time
};

int32_t main() {
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> adj(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v, s, d, t;
        cin >> u >> v >> s >> d >> t;
        adj[u].push_back({v, s, d, t});
    }

    vector<int> dist(n + 1, INF);
    dist[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1}); // time, node

    while (!pq.empty()) {
        auto [curTime, u] = pq.top(); pq.pop();
        if (curTime > dist[u]) continue;

        for (auto &e : adj[u]) {
            int waitTime = 0;
            if (curTime <= e.s) waitTime = e.s - curTime;
            else {
                int missed = (curTime - e.s + e.d - 1) / e.d;
                waitTime = e.s + missed * e.d - curTime;
            }

            int arrival = curTime + waitTime + e.t;
            if (dist[e.to] > arrival) {
                dist[e.to] = arrival;
                pq.push({arrival, e.to});
            }
        }
    }

    cout << (dist[n] == INF ? -1 : dist[n]) << '\n';
}
```

---

## 🔹 Key Takeaways

* Time becomes part of your state
* Edge cost is a function of arrival time
* Must simulate "next possible departure" based on constraints

---

## 📁 Practice Problems

* [CSES - Time-Dependent Dijkstra](https://cses.fi/problemset/task/1202/)
* [Leetcode 1928 - Minimum Cost to Reach Destination in Time](https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/)
* \[Google Kickstart - Train Timetable Variants]

---

✅ You've now completed the **full Dijkstra Variants Track**!

Consider practicing contest-level problems or try implementing Dial’s algorithm and A\* search as extensions.
