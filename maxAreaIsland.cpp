class Solution {
private:
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int n, int m) {
        if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == 0 || vis[row][col]) {
            return 0;
        }
        vis[row][col] = 1;
        int area = 1; // Count the current cell
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            area += dfs(nrow, ncol, grid, vis, n, m); // Add the area of connected cells
        }
        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi = 0;
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    maxi = max(maxi, dfs(i, j, grid, vis, n, m));
                }
            }
        }
        return maxi;
    }
};