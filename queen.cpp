class Solution {
    private:
        void queen(int col,vector<string>&board,vector<vector<string>>&ans,vector<int>&left,vector<int>& udiag,vector<int>& ldiag){
            if(col == board.size()){
                ans.push_back(board);
                return;
            }
           for(int row=0;row<board.size();row++){
                if(!left[row] && !udiag[board.size()-1 + col - row] && !ldiag[row+col]){
                    left[row] = 1;
                    udiag[board.size()-1 + col -row] =1;
                    ldiag[row + col] = 1;
                    board[row][col] = 'Q';
                    queen(col+1,board,ans,left,udiag,ldiag);
                    board[row][col] = '.';
                    left[row] = 0;
                    udiag[board.size()-1 + col -row] =0;
                    ldiag[row + col] = 0;
                }
           } 
        }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s;
        vector<int>left(n*2,0),udiag(n*2,0),ldiag(n*2,0);
        for(int i=0;i<n;i++){
            s+='.';
        }

        for(int i=0;i<n;i++){
            board[i] = s;
        }
        queen(0,board,ans,left,udiag,ldiag);

        return ans;
    }
};
