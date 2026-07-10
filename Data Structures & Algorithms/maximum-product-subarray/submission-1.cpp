class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];

        int productL = 1;
        int productR = 1;

        for (int i = 0; i < n; i++) {
            productL *= nums[i];

            if (productL > res) {
                res = productL;
            }

            if (nums[i] == 0) {
                productL = 1;
                if (res < 0) {
                    res = 0;
                }
            }

            int j = n - 1 - i;
            productR *= nums[j];
            if (productR > res) {
                res = productR;
            }

            if (nums[j] == 0) {
                productR = 1;
                if (res < 0) {
                    res = 0;
                }
            }
        }

        return res;
    }
};
