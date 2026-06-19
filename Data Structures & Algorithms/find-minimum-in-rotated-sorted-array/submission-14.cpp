class Solution {
public:
    int findMin(vector<int> &nums) {
        int currMin = INT_MAX;
        int l = 0;
        int r = nums.size() - 1;
        int mid = l + (r - l) / 2;
        if (nums[l] <= nums[r]) { return nums[l]; }
        
        while(l != r) {
            currMin = min(currMin, nums[mid]);
            if (nums[l] <  nums[mid] && nums[mid] < nums[r]) { 
                return nums[l]; 
            } else if (nums[l] > nums[mid] && nums[r] > nums[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
            mid = l + (r - l) / 2;
            currMin = min(currMin, nums[mid]);


        }
        return currMin;
    }
};
/*
        perfectly sorted, just need to see if left is less than r
        0   1   2   3   4   5   6       l < m < r
        l           m           r

        6   0   1   2   3   4   5       l > m < r,  l > r
        l           m           r

        5   6   0   1   2   3   4       l > m < r,  l > r
        l           m           r

        4   5   6   0   1   2   3       l > m < r,  l > r
        l           m           r

        3   4   5   6   0   1   2       l < m > r,  l > r
        l           m           r

        2   3   4   5   6   0   1       l < m > r,  l > r
        l           m           r

        1   2   3   4   5   6   0       l < m > r,  l > r
        l           m           r

*/
