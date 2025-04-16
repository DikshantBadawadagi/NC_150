class Solution {
    private:
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>& grid){
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();

        vector<int>drow = {-1,0,1,0};
        vector<int>dcol = {0,1,0,-1};

        for(int i=0;i<4;i++){
            int nrow = drow[i] + row;
            int ncol = dcol[i] + col;

            if(nrow>=0 && nrow < n && ncol>=0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                dfs(nrow,ncol,vis,grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};
