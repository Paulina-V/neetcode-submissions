class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int c = 0; c < grid[0].size(); c++) {
            for (int r = 0; r < grid.size(); r++) {
                if (grid[r][c] == '1') {
                    count++;

                    dfs(grid, r, c);
                }
            }
        }

        return count;
    }
    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == '0') {
            return;
        }
        grid[r][c] = '0';
        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
    }
};
