class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        // reflect over the middle
        int upperRow = 0;
        int lowerRow = matrix.size() - 1;

        while (upperRow < lowerRow) {
            for (int i = 0; i < matrix[0].size(); i++) {
                // swap matrix[upperRow][i] and matrix[lowerRow][i]
                int temp = matrix[upperRow][i];
                matrix[upperRow][i] = matrix[lowerRow][i];
                matrix[lowerRow][i] = temp;
            }
            upperRow++;
            lowerRow--;
        }

        // reflect over diagonal

        for (int c = 0; c < matrix[0].size(); c++) {  
            for (int r = c + 1; r < matrix.size(); r++) {
                int temp = matrix[r][c];
                matrix[r][c] = matrix[c][r];
                matrix[c][r] = temp;
            }
        }
    }
};
