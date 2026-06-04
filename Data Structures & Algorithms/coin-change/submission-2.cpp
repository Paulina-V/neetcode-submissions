class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // build up the coins from 1 to amount and store the number of coins needed

        
        vector<int> dp(amount + 1, INT_MAX); // to store the min number of coins used for each amount
        dp[0] = 0;
        
        for (int i = 1; i < amount + 1; i++) {
            for (int c : coins) {
                if (i - c < 0) continue;
                if (dp[i - c] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - c] + 1);
                }
            }
        }
        if (dp[amount] == INT_MAX) return -1;
        return dp[amount];

    }
};
