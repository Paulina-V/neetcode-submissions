class Solution {

public:

    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int absCurrent = abs(nums[i]);
            if(nums[absCurrent - 1] < 0) {
                return absCurrent;
            }
            nums[absCurrent - 1] = -nums[absCurrent - 1];  
        }
        return -1;
    }
};
