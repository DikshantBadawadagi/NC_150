#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

vector<vector<int>> adj(MAXN);
vector<int> visited; // 0 = unvisited, 1 = visiting, 2 = done
vector<int> topo;

void dfs(int u) {
    visited[u] = 1;
    for (int v : adj[u]) {
        if (visited[v] == 0) {
            dfs(v);
        }
    }
    visited[u] = 2;
    topo.push_back(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    
    visited.assign(n + 1, 0);
    dfs(1); // Start from 1
    reverse(topo.begin(), topo.end());
    
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    
    for (int u : topo) {
        if (dp[u] == 0) continue; // Skip unreachable from 1
        for (int v : adj[u]) {
            dp[v] = (dp[v] + dp[u]) % MOD;
        }
    }
    
    cout << dp[n] << "\n";
    
    return 0;
}