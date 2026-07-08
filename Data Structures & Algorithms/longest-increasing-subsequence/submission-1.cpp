class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1); // dp[i] holds the length of the longest 
                        // increasing subsequence ending at nums[i]
        int ret = 1;
        for (int i = 0; i < nums.size(); i++) { // try all i vals to end the subseq
            for(int j = 0; j < i; j++){
                // find the count that ends here
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    ret = max(ret, dp[i]);
                }
            }
        }
        return ret;
    }
};
