    //int n,m; cin>>n>>m;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    // vector<vector<pi>> adj(n+1);
    // for(int i=0; i<m; i++) {
    //     int u,v,w; cin>>u>>v>>w;
    //     adj[u].push_back({v,w});
    //     adj[v].push_back({u,w});
    // }
    pq.push({0,1});
    vi vis(n+1);
    int cost = 0; int cnt=0;
    while(!pq.empty()) {
        auto [wt,u] = pq.top(); pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        cost += wt; cnt++;
        for(auto& [v,w]: adj[u]) {
            if(!vis[v]) {
                pq.push({w,v});
            }
        }
    }
    //if(cnt!=n) {cout<<"IMPOSSIBLE"<<nl; return;} [not a connected graph]
    //cout<<cost<<"\n";
    //cnt tells if the graph is not a single connected componemt
