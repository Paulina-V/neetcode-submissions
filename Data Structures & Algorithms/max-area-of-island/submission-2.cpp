class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for (int c = 0; c < grid[0].size(); c++) {
            for (int r = 0; r < grid.size(); r++) {
                maxArea = max(maxArea, dfs(grid, r, c));
            }
        }
        return maxArea;
    }
    int dfs (vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0) { return 0; }
        
        grid[r][c] = 0;
    
        return 1 + dfs(grid, r + 1, c) + dfs(grid, r, c + 1) + dfs(grid, r, c - 1) + dfs(grid, r - 1, c);
    }
};