class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> currCombo;
        sort(nums.begin(), nums.end());
        dfs(target, currCombo, 0, nums);
        return ret;
    }

    void dfs(int target, vector<int>& currCombo, int i, vector<int>& nums) {
        if (target == 0) {
            ret.push_back(currCombo); // good combo
            return;
        }
        if(i > nums.size() - 1 || target < 0) {
            return;
        }
        if (target - nums[i] >= 0) {
            currCombo.push_back(nums[i]);   
            dfs(target - nums[i], currCombo, i, nums);
            currCombo.pop_back();
            dfs(target, currCombo, i + 1, nums);
        }
        
    }
};
