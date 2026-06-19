class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        if (nums[l] <= nums[r]) { return nums[l]; }
        
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return nums[l];
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
