class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        vector<pair<int, int>> directions;
        directions.push_back({0, 1});
        directions.push_back({1, 0});
        directions.push_back({0, -1});
        directions.push_back({-1, 0});
        queue<pair<int, int>> q;
        for (int c = 0; c < grid[0].size(); c++) {
            for (int r = 0; r < grid.size(); r++) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        while (q.size() != 0) {
            // bfs loop
            pair<int, int> loc = q.front();
            int r = loc.first;
            int c = loc.second;
            q.pop();

            for (pair<int, int> d : directions) {
                int newR = r + d.first;
                int newC = c + d.second;
             
                if (newR < 0 || newC < 0 || newR > grid.size() - 1 || newC > grid[0].size() - 1) {
                    // the current cell is out of bounds so do nothing
                } else {
                    if (grid[newR][newC] == 2147483647) {
                        grid[newR][newC] = grid[r][c] + 1;
                        q.push({newR, newC});
                    }
                }
            }
        }
    }
};