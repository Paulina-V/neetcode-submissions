class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        bool rowZero = false;

        vector<pair<int, int>> originalZeros;
        for (int c = 0; c < matrix[0].size(); c++) {
            for (int r = 0; r < matrix.size(); r++) {
                if (matrix[r][c] == 0) {
                    matrix[0][c] = 0;
                    if (r > 0) {
                        matrix[r][0] = 0;
                    } else {
                        rowZero = true;
                    }
                }
            }
        }
        for (int c = 1; c < cols; c++) {
            for (int r = 1; r < rows; r++) {
                if (matrix[0][c] == 0 || matrix[r][0] == 0) {
                    matrix[r][c] = 0;
                }
            }
        }
        if (matrix[0][0] == 0) {
            for (int r = 0; r < rows; r++) {
                matrix[r][0] = 0;
            }
        }
        if (rowZero) {
            for (int c = 0; c < cols; c++) {
                matrix[0][c] = 0;
            }
        }
    }
};
