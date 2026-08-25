class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        vector<int> currCombo;
        dfs(nums, currCombo, 0, ret);
        return ret;
    }

    void dfs(vector<int>&nums, vector<int> currCombo, int i, vector<vector<int>>& ret) {
        if (i == nums.size()) { // i is the first unproccessed element
            ret.push_back(currCombo);
            /*
            for(auto& r : ret) {
                cout << "currCombo:";
                for(int c : r) {
                    cout << c << " ";
                }
                cout << "\n";
            }
            */
            return; 
        }
    

        currCombo.push_back(nums[i]);
        dfs(nums, currCombo, i + 1, ret);
        currCombo.pop_back();
        while(i < nums.size() - 1 && nums[i] == nums[i+1]){
            i++;
        }
        dfs(nums, currCombo, i + 1, ret);

    }
};
