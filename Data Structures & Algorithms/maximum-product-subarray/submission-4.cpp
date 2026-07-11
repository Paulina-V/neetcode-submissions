class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curMax = 1;
        int curMin = 1;

        for (int n : nums) {
            int temp1 = curMax * n;
            int temp2 = curMin * n;
            curMax = max(n, max(temp1, temp2));
            curMin = min(n, min(temp1, temp2));
            res = max(res, curMax);
        }
        return res;
    }
};
