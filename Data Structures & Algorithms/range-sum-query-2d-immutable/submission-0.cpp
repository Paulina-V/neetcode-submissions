class NumMatrix {
private: 
    vector<vector<int>> sum;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        sum = vector<vector<int>>(rows + 1, vector<int>(cols+1, 0));
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                int currCell = matrix[r][c];
                sum[r+1][c+1] = sum[r+1][c] + sum[r][c+1] - sum[r][c] + currCell;   
            }

        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2 +1 ][col2 + 1]
                - sum[row2  + 1][col1 - 1 + 1] 
                - sum[row1 - 1 + 1][col2 + 1] 
                + sum[row1 - 1 + 1][col1 - 1 + 1];
    }

   
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */