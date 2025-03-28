#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            set<char> rowSet, colSet, boxSet;
            for(int j = 0; j < 9; j++) {
                // Row check
                char rowItem = board[i][j];
                if (rowItem != '.') {
                    if (rowSet.find(rowItem) != rowSet.end()) {
                        return false;
                    }
                    rowSet.insert(rowItem);
                }

                // Column check
                char colItem = board[j][i];
                if (colItem != '.') {
                    if (colSet.find(colItem) != colSet.end()) {
                        return false;
                    }
                    colSet.insert(colItem);
                }

                // 3x3 sub-box check
                int rowIndex = 3 * (i / 3) + j / 3;
                int colIndex = 3 * (i % 3) + j % 3;
                char boxItem = board[rowIndex][colIndex];
                if (boxItem != '.') {
                    if (boxSet.find(boxItem) != boxSet.end()) {
                        return false;
                    }
                    boxSet.insert(boxItem);
                }
            }
        }
        return true;
    }
};