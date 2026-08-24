class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int lo = 0, hi = m*n - 1; // first and last elements

        while (lo <= hi) { // start and end haven't met yet
            int mid = lo + (hi - lo) / 2;
            int row = mid / n;
            int col = mid % n;
            int val = matrix[row][col];
        
            if (val < target) {
                lo = mid + 1;
            } else if (val > target) {
                hi = mid - 1;
            } else {
                return true;
            
            }
        }
        return false;

    }
};
        