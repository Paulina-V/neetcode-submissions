class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % 2 != 0) return false;

        vector<int> dp(nums.size(), -1);

        return dfs(0, sum / 2, nums, 0, dp);
    }

    bool dfs (int i, int target, vector<int>& nums, int curSum, vector<int>& dp) {
        if (curSum == target) return true;
        if (i == nums.size() || curSum > target) return false;

        if (dp[i] == 0) return false;
        if (dp[i] == 1) return true;

        bool include = dfs (i + 1, target, nums, curSum + nums[i], dp);
        if (include == true) {
            dp[i] = 1;
        } else {
            dp[i] = -1;
        }
        bool exclude = dfs (i + 1, target, nums, curSum, dp);
        if (exclude == true) {
            dp[i] = 1;
        } else {
            dp[i] = -1;
        }

        return include || exclude;
    }
};
