#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& edge : times) {
            int u = edge[0], v = edge[1], t = edge[2];
            adj[u].push_back({v, t});
        }

        vector<long long> dist(n + 1, LLONG_MAX);
        dist[k] = 0;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, k});

        vector<bool> visited(n + 1, false);
        int nodesVisited = 0;

        while (!pq.empty()) {
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (visited[u]) continue;
            visited[u] = true;
            nodesVisited++;

            for (const auto& [v, t] : adj[u]) {
                if (d + t < dist[v]) {
                    dist[v] = d + t;
                    pq.push({dist[v], v});
                }
            }
        }

        if (nodesVisited != n) {
            return -1;
        }

        long long maxDist = 0;
        for (int i = 1; i <= n; i++) {
            maxDist = max(maxDist, dist[i]);
        }

        return maxDist == LLONG_MAX ? -1 : maxDist;
    }
};
