class Solution {
public:

    bool exist(vector<vector<char>>& board, string word) {
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                if (helper(board, word, r, c, 0)) return true;
            }
        }
        return false;
    }

    bool helper(vector<vector<char>>& board, string& word, int row, int col, int i){
        if (i == word.length()) return true;

        if  (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != word[i]) {
            return false;
        }
        char temp = board[row][col];
        board[row][col] = '.';
        bool found = helper(board, word, row - 1, col, i + 1)
            || helper(board, word, row + 1, col, i + 1)
            || helper(board, word, row, col - 1, i + 1)
            || helper(board, word, row, col + 1, i + 1);
        
        board[row][col] = temp;

        return found;
    }
};