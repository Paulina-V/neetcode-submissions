class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> currCombo;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, currCombo);
        return ret;
        
    }
    
    void dfs(vector<int>&candidates, int target, int i, vector<int>& currCombo) {
        if (target == 0) {
            ret.push_back(currCombo);
            return;
        }
        if (i >= candidates.size() || target < 0) {
            return;
        }

        currCombo.push_back(candidates[i]);
        dfs(candidates, target - candidates[i], i + 1, currCombo);
        currCombo.pop_back();


        while ((i+1 < candidates.size()) && (candidates[i+1] == candidates[i])) {
            i++;
            
        }

        dfs(candidates, target, i + 1, currCombo);
    }
};
