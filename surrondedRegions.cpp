class Solution {
    private:
    void dfs(int row,int col,vector<vector<char>>& board,int n,int m){
        board[row][col] = '#';
        vector<int>drow = {-1,0,1,0};
        vector<int>dcol = {0,1,0,-1};

        for(int i=0;i<4;i++){
            int nrow  = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == 'O'){
                dfs(nrow,ncol,board,n,m);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0;i<n;i++){
            if(board[i][0] == 'O'){
                dfs(i,0,board,n,m);
            }
            if( board[i][m-1] == 'O')
            dfs(i,m-1,board,n,m);
        }
        for(int i=0;i<m;i++){
            if(board[0][i] == 'O'){
                dfs(0,i,board,n,m);
            }
            if(board[n-1][i] == 'O'){
                dfs(n-1,i,board,n,m);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O'){
                    board[i][j] =  'X';
                }
                else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
