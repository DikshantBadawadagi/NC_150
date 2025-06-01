class Solution {
    private:
    int f(int row,int col,int m, int n,vector<vector<int>>&dp){

        if(row >= m || col >= n)return 0;

        if(row == m-1 && col == n-1)return 1;

        if(dp[row][col] != -1)return dp[row][col];

        int down = f(row+1,col,m,n,dp);

        int right = f(row,col + 1,m,n,dp);

        return dp[row][col] = down + right;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        dp[m-1][n-1] = 1;

        for(int row = m-1;row>=0;row--){
            for(int col = n-1;col >= 0;col--){

                 if (row + 1 < m)
                    dp[row][col] += dp[row + 1][col];
                if (col + 1 < n)
                    dp[row][col] += dp[row][col + 1];

            }
        }
        return dp[0][0];

    }
};
