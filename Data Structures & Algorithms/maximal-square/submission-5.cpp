class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> memo(matrix.size(), vector<int>(matrix[0].size(), 0));

        int ret = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                int len = helper(matrix, i, j, memo);
                ret = max(len, ret);
            }
        }
        return ret * ret;

        
    }
    int helper(vector<vector<char>>& matrix, int i, int j, vector<vector<int>>& memo) { // returns the max dimension of the square starting from matrix[i][j]
        //cout << "i " << i << "   j " << j << "   matrix[i][j] " << matrix[i][j] << "\n";
        if (i >= matrix.size() ||j >= matrix[0].size()) return 0;
        if (matrix[i][j] == '0') return 0;
        if (memo[i][j] != 0) return memo[i][j];

        int sizeDown = helper(matrix, i + 1, j, memo);
        int sizeRight = helper(matrix, i, j + 1, memo);
        int sizeDiag = helper(matrix, i + 1, j + 1, memo);
        
        memo[i][j] = 1 + min(sizeDiag, min(sizeDown, sizeRight));
        return memo[i][j];
    }
};

// brute force approach:
            // loop through each entry in the matrix and for each of them, treat that square as if it's the top left entry of the square with 1s. create a max square width and a max square height then while the values in said square are still one, go to the right and increment the max square length until it's not one. then move to the next row and do the same thing. but if the row stops earlier, then decrement the length. this should go on for the appropriate number of rows (based on what the max square lenght is, it should match that)


        // recursive no memo approach:
        
            // base case: if matrix[i][j] == 0 return the size;
            // 
        // recursive yes memo approach:
        // dp approach: