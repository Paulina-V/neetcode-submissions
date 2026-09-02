class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> squares(9);
        vector<int> sizes(9);

        for (int r = 0; r < 9; r++) {
            unordered_set<char> colSet;
            unordered_set<char> rowSet;
            int colCt = 0;
            int rowCt = 0;
            for(int c = 0; c < 9; c++) {
                if(board[r][c] != '.') {
                    colCt++;
                    colSet.insert(board[r][c]);
                }
                if(board[c][r] != '.') {
                    rowCt++;
                    rowSet.insert(board[c][r]);
                }
                if(board[c][r] != '.') {
                    int boxIndex =  (r/3) * 3 + (c/3);
                    squares[boxIndex].insert(board[c][r]);
                    sizes[boxIndex]++ ;
                }
            }
            if(colSet.size() != colCt || rowSet.size() != rowCt) {
                return false;
            }
        }
        for(int i = 0; i < 9; i++){
            if(squares[i].size() != sizes[i]) return false;
        }
        return true;
    }
};
