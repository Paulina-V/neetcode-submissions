class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> products (nums.size());
        vector<int> prefix (nums.size() + 2, 1);
        vector<int> suffix (nums.size() + 2, 1);
        for(int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] * nums[i];
        }
        for(int i = nums.size() - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i];
        }
        for(int i = 0; i < nums.size(); i++){
            products[i] = prefix[i] * suffix[i + 1];
        }
        return products;
    }
};

