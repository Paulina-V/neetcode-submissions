class Solution {
public:
    vector<bool> bools;
    vector<vector<int>> rets;

    vector<vector<int>> permute(vector<int>& nums) {
        bools.assign(nums.size(), false);
        vector<int> curr;
        helper (curr, nums);
        return rets;
    }
    void helper(vector<int> curr, vector<int>& nums) {
        if (curr.size() == nums.size()) {
            rets.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if(bools[i] == false) {
                bools[i] = true;
                curr.push_back(nums[i]);
                helper(curr, nums);
                curr.pop_back();
                bools[i] = false;
            }
            
        }
    }
};




