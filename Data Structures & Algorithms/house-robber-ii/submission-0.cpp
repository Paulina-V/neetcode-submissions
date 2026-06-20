class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1) return nums[0];
        int choice1 = robRange(nums, 0, n - 2);
        int choice2 = robRange(nums, 1, n - 1);
        return max(choice1, choice2);
    }

private:
    int robRange(vector<int>& nums, int start, int end) {
        int rob1 = 0; // 2 houses ago
        int rob2 = 0; // 1 house ago
        
        for (int i = start; i <= end; i++) {
            int currentMax = max(rob1 + nums[i], rob2);
            rob1 = rob2;
            rob2 = currentMax;
        }
        return rob2;
    }
};