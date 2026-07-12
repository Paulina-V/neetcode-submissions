class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curMax = 1;
        int curMin = 1;

        for (int num : nums) {
            int temp1 = curMax * num;
            int temp2 = curMin * num;
            curMax = max(num, max(temp1, temp2));
            curMin = min(num, min(temp1, temp2));
            res = max(res, curMax);
        }
        return res;
    }
};
