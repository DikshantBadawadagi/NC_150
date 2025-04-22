class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int>indegree(n+1,0);
        vector<vector<int>>adj(n+1);

        for(vector<int> & vec : pre){
            adj[vec[1]].push_back(vec[0]);
            indegree[vec[0]]++;
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if( indegree[i] == 0){
                q.push(i);
            }
        }

        if(q.empty()){
            return {};
        }
        vector<int>ans;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto neigh : adj[node]){
                indegree[neigh]--;
                if(!indegree[neigh]){
                    q.push(neigh);
                }
            }
        }
        if(ans.size() != n)return {};

        return ans;

    }
};
