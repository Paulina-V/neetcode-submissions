class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int c = 0; c < grid[0].size(); c++) {
            for (int r = 0; r < grid.size(); r++) {
                cout << count << " ";
                cout << "r:" << r << " c:" << c << " grid[r][c]:" << grid[r][c] << "\n";
                if (grid[r][c] == '1') {
                    //cout << "inner r:" << r << " c:" << c << " grid[r][c]:" << grid[r][c];
                    count++;
                    grid[r][c] = '0';
                    if (r > 0) {
                        dfs(grid, r - 1, c);
                    } 
                    if (c > 0) {
                        dfs(grid, r, c - 1);
                    }
                    if (r < grid.size() - 1) {
                        dfs(grid, r + 1, c);
                    }
                    if (c < grid[0].size() - 1) {
                        dfs(grid, r, c + 1);
                    }
                }
            }
        }

        return count;
    }
    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (grid[r][c] == '0') {
            return;
        }
       // cout << "dfs r:" << r << " c:" << c << " grid[r][c]:" << grid[r][c];
        grid[r][c] = '0';

        if (r > 0) {
            dfs(grid, r - 1, c);
        } 
                    if (c > 0) {
                        dfs(grid, r, c - 1);
                    }
                    if (r < grid.size() - 1) {
                        dfs(grid, r + 1, c);
                    }
                    if (c < grid[0].size() - 1) {
                        dfs(grid, r, c + 1);
                    }

        
    }
};

