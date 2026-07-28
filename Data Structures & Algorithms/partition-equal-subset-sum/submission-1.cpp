class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int n : nums) totalSum += n;
        if (totalSum % 2 != 0) return false; // if the sum of elements is odd --> return false;

        int halfSum = totalSum / 2;     // goal is to build a subset with sum = half of total sum
        return dfs(0, 0, halfSum, nums);
    }
    bool dfs(int i, int currSum, int target, vector<int>& nums) { 
        if (currSum == target) return true;
        if (i >= nums.size() || currSum > target) return false;
        return dfs(i + 1, currSum + nums[i], target, nums) || dfs(i + 1, currSum, target, nums);
    }
};
