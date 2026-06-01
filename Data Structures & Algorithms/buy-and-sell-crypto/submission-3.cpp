class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 0;
        int maxProfit = 0;
        if(prices.size() <= 1) { return 0; }
        while (right < prices.size() && left < prices.size()) {
            if(right == left) { right++; }
            if (prices[right] < prices[left]) {
                left = right;
                right ++;
            } else {
                maxProfit = max(prices[right] - prices[left], maxProfit); 
                right++;
            }
        }
        return maxProfit;
    }
};
