class Solution {
public:


bool canReach(vector<vector<int>>& grid, int t) {
    int n = grid.size();
    if (grid[0][0] > t || grid[n-1][n-1] > t) return false; // Can't start or end if elevation > t
    
    // BFS setup
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    
    // Directions for 4-directional movement: up, right, down, left
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        // If we reached the target
        if (x == n-1 && y == n-1) return true;
        
        // Explore 4 directions
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            
            // Check bounds and if unvisited and elevation <= t
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && grid[nx][ny] <= t) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return false;
}

int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    int left = 0, right = n * n - 1; // Range of t based on elevation constraints
    int ans = right;
    
    // Binary search on time t
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canReach(grid, mid)) {
            ans = mid; // Found a possible t, try to minimize
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

};
