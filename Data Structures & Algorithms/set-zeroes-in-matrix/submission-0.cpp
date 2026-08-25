class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> originalZeros;
        for (int c = 0; c < matrix[0].size(); c++) {
            for (int r = 0; r < matrix.size(); r++) {
                if (matrix[r][c] == 0) {
                    originalZeros.push_back({r,c});
                }
            }
        }
        for (auto& p : originalZeros) {
            helper(p.first, p.second, matrix);
        }
    }
    void helper(int r, int c, vector<vector<int>>& matrix) {
        // given index r and c, set the matrix row and coluumn to 0
        for (int i = 0; i < matrix[0].size(); i++) {
            matrix[r][i] = 0;
        }
        for (int i = 0; i < matrix.size(); i++) {
            matrix[i][c] = 0;
        }
    }
};
