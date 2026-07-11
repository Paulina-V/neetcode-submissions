class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];

        int productL = 1;
        int productR = 1;

        for (int i = 0; i < n; i++) {
            productL *= nums[i];
            if (productL > res) { // if the left product is better than the current max product
                res = productL; // max = left
            }

            if (nums[i] == 0) {  
                productL = 1;
                //if (res < 0) res = 0;
            }

            int j = n - 1 - i; // j is the ith from the right 
            productR *= nums[j]; 
            if (productR > res) { // if the right product is better than the current max product
                res = productR;
            }

            if (nums[j] == 0) {
                productR = 1;
                //if (res < 0) res = 0;

            }
        }

        return res;
    }
};
