class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> curr = {0, 0, 0};
        for (vector<int> trip : triplets) {
            if (trip[0] == target[0] && trip[1] <= target[1] && trip[2] <= target[2] ||
                trip[1] == target[1] && trip[0] <= target[0] && trip[2] <= target[2] ||
                trip[2] == target[2] && trip[0] <= target[0] && trip[1] <= target[1]) {
                for (int i = 0; i < 3; i++) curr[i] = max(trip[i], curr[i]);
            }
        }
        for (int i = 0; i < 3; i++) {
            if (curr[i] != target[i]) return false;
        } 
        return true;
    }
};
