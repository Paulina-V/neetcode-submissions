class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> currCombo;
        sort(nums.begin(), nums.end());
        dfs(nums, target, currCombo, 0);
        return ret;
    }

    void dfs(vector<int>& nums, int target, vector<int>& currCombo, int currMax) {
        if (target == 0) {
            ret.push_back(currCombo); // good combo
            return;
        }
        for (int n : nums) {
            if(target - n >= 0 && n >= currMax) {
                currCombo.push_back(n);
                dfs(nums, target - n, currCombo, n);
                currCombo.pop_back();
            }
        }
    }
};
