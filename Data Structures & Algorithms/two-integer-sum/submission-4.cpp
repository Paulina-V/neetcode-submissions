class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            int match = target - nums[i];
            for (int j = i + 1; j < nums.size(); j++)  {
                if (nums[j] == match) {
                    std::vector<int> ret = {i, j};
                    return ret;
                }
            }
        }
    }
};
