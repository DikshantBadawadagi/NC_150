class Solution {
private:
    bool dfs(int i, vector<int>& vis, vector<int>& pathVis, vector<vector<int>>& adj) {
        vis[i] = 1;
        pathVis[i] = 1;

        for (auto neigh : adj[i]) {
            if (!vis[neigh]) {
                if (dfs(neigh, vis, pathVis, adj)) return true;
            } else if (pathVis[neigh]) {
                // back edge -> cycle
                return true;
            }
        }

        pathVis[i] = 0;
        return false;
    }

public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> vis(n, 0), pathVis(n, 0);
        vector<vector<int>> adj(n);

        for (vector<int>& num : pre) {
            adj[num[1]].push_back(num[0]);
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, pathVis, adj)) return false;
            }
        }

        return true;
    }
};
