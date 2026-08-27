class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> subset;
        dfs(nums, 0, subset, ret);
        return ret;
    }

private:
    void dfs(vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>&ret){
        if (i >= nums.size()) {
            ret.push_back(subset);
            return;
        }
        dfs(nums, i + 1, subset, ret);
        subset.push_back(nums[i]);
        dfs(nums, i + 1, subset, ret);
        subset.pop_back();
    }    
};