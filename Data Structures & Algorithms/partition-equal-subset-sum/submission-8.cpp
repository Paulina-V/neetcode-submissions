class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % 2 != 0) return false;

        vector<vector<int>> dp(nums.size(), vector<int>(sum/2 + 1, -1));

        return dfs(0, sum / 2, nums, 0, dp);
    }

    bool dfs (int i, int target, vector<int>& nums, int curSum, vector<vector<int>>& dp) {
        if (curSum == target) return true;
        if (i == nums.size() || curSum > target) return false;

        if (dp[i][curSum] == 0) return false;
        if (dp[i][curSum] == 1) return true;

        bool include = dfs (i + 1, target, nums, curSum + nums[i], dp);
        
        bool exclude = dfs (i + 1, target, nums, curSum, dp);
        bool res = include || exclude;
        dp[i][curSum] = res ? 1 : 0;

        return include || exclude;
    }
};
