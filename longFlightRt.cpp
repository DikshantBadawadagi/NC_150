// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n,m;
//     cin>>n>>m;
//     vector<vector<int>>adj(n+1);
//     vector<int>indegree(n+1,0);

//     for(int i=0;i<m;i++){
//         int a,b;
//         cin>>a>>b;
//         adj[a].push_back(b);
//         indegree[b]++;
//     }
//     queue<int>q;

//     for(int i=1;i<=n;i++){
//         if(indegree[i]== 0){
//             q.push(i);
//         }
//     }
//     vector<int>topo;

//     while(!q.empty()){
//         int node = q.front();
//         topo.push_back(node);
//         q.pop();
//         for(auto it: adj[node]){
//             indegree[it]--;
//             if(indegree[it] == 0){
//                 q.push(it);
//             }
//         }
//     }
//     vector<int>dp(n+1,0);
//     vector<int>parent(n+1,-1);
//     dp[1] = 1;

//     for(int i=0;i<n;i++){
//         int node = topo[i];
//         for(auto it : adj[node]){
//             if(dp[it] < dp[node] + 1){
//                 dp[it] = dp[node] + 1;
//                 parent[it] = node;
//             }
//         }
//     }
//     if(dp[n] == 0) {
//         cout << "IMPOSSIBLE\n";
//         return 0;
//     }
//     int ind = n;
//     cout<<dp[n]<<endl;
//     vector<int>path;
//     while(parent[ind] != -1){
//         path.push_back(ind);
//         ind = parent[ind];
//     }
//     path.push_back(1);
//     reverse(path.begin(),path.end());
//     for(auto it : path){
//         cout<<it<<" ";
//     }
//     cout<<endl;

// }
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }

    // BFS to get nodes reachable from 1
    vector<bool> reachable(n + 1, false);
    queue<int> q;
    q.push(1);
    reachable[1] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int v : adj[node]) {
            if (!reachable[v]) {
                reachable[v] = true;
                q.push(v);
            }
        }
    }

    if (!reachable[n]) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // Kahn’s Topo Sort
    vector<int> topo;
    q.push(1);
    while (!q.empty()) {
        int node = q.front();
        topo.push_back(node);
        q.pop();
        for (int v : adj[node]) {
            if (--indegree[v] == 0 && reachable[v]) {
                q.push(v);
            }
        }
    }

    vector<int> dp(n + 1, 0);
    vector<int> parent(n + 1, -1);
    dp[1] = 1;

    for (int node : topo) {
        if (dp[node] == 0) continue; // Skip if not reachable from 1
        for (int v : adj[node]) {
            if (dp[v] < dp[node] + 1) {
                dp[v] = dp[node] + 1;
                parent[v] = node;
            }
        }
    }

    if (dp[n] == 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << dp[n] << "\n";
    vector<int> path;
    int ind = n;
    while (ind != -1) {
        path.push_back(ind);
        ind = parent[ind];
    }
    reverse(path.begin(), path.end());
    for (int v : path) {
        cout << v << " ";
    }
    cout << "\n";

    return 0;
}