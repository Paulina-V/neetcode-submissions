class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int n : nums) totalSum += n;
        if (totalSum % 2 != 0) return false; // if the sum of elements is odd --> return false;

        int target = totalSum / 2;     // goal is to build a subset with sum = half of total sum
        vector<vector<int>> memo(nums.size(), vector<int>(target + 1, -1));
        return dfs(0, 0, target, nums, memo);
    }
    bool dfs(int i, int currSum, int target, vector<int>& nums, vector<vector<int>>& memo) { 
        if (currSum == target) return true;
        if (i >= nums.size() || currSum > target) return false;

        if (memo[i][currSum] != -1) return memo[i][currSum];
        bool result = dfs(i + 1, currSum + nums[i], target, nums, memo) || dfs(i + 1, currSum, target, nums, memo);
        memo[i][currSum] = result;
        return result;   
    }
};
