class Solution {
public:
    int search(vector<int>& nums, int target) {
        int startI = 0; 
        int endI = nums.size() - 1;
        while(startI <= endI) {
            int mid = startI + (endI - startI)/2;
            if (nums[mid] <  target) {
                startI = mid + 1;
            } else if(nums[mid] > target) {
                endI = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};
