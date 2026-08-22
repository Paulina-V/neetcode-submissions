class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        vector<pair<int, int>> directions;
        directions.push_back({0, 1});
        directions.push_back({0, -1});
        directions.push_back({-1, 0});
        directions.push_back({1, 0});

        queue<vector<int>> fruits; // r, c, time
        for(int c = 0; c < grid[0].size(); c++) {
            for (int r = 0; r < grid.size(); r++) {
                if (grid[r][c] == 2) {
                    fruits.push({r,c, time});
                }
            }
        }
        while (fruits.size() != 0) {

            int r = fruits.front()[0];
            int c = fruits.front()[1];
            int t = fruits.front()[2];
            fruits.pop();
            // when we pop things off the queue, all vals with the same t happen together
            if (t != time) { 
                time++;
            }
            for (pair<int, int> d : directions) {
                int newR = d.first + r;
                int newC = d.second + c;
                if (newR >= 0 && newC >= 0 && newR < grid.size() && newC < grid[0].size() && grid[newR][newC] != 0 && grid[newR][newC] != 2) {
                    grid[newR][newC] = 2;
                    
                    fruits.push({newR, newC, time + 1});
                }
                
            }
        }

        for(int c = 0; c < grid[0].size(); c++) {
            for (int r = 0; r < grid.size(); r++) {
                if (grid[r][c] == 1) {
                    return -1;
                }
            }
        }
        return time;
    }
};

