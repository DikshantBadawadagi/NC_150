#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    priority_queue<pair<int, int>> pq;
    pq.push({0, 1}); // Max-heap (storing distances as negative)

    vector<int> vis(n + 1, 0); // Count number of times a node is visited

    while (!pq.empty() && vis[n] < k) {
        auto [cost, node] = pq.top();
        pq.pop();

        cost = -cost; // Convert back to positive weight
        vis[node]++;

        if (node == n) cout << cost << " "; // Print valid kth shortest path
        
        if (vis[node] <= k) {
            for (auto [nnode, w] : adj[node]) {
                pq.push({-(cost + w), nnode}); // Store negative cost
            }
        }
    }

    if (vis[n] < k) cout << -1; // If fewer than k paths exist, return -1

    cout << endl;
    return 0;
}
