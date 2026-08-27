class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int rows = board.size(); 
        int cols = board[0].size();

        for (int r = 0; r < rows; r++) {
            dfs(board, r, 0);
            dfs(board, r, cols - 1);
        }

        for (int c = 0; c < cols; c++) {
            dfs(board, 0, c);
            dfs(board, rows - 1, c);
        }        

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }

private:
    void dfs(vector<vector<char>>& board, int i, int j) {
        int rows = board.size(), cols = board[0].size();
        if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != 'O') return; // oob

        board[i][j] = '#'; // mark this one as seen
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }
};
