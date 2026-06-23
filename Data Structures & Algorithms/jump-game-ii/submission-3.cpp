class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> minJumps(nums.size(), 1001);

        minJumps[nums.size() - 1] = 0;
        for (int i = nums.size() - 2; i >= 0; i--) {
            for (int j = 1; j <= nums[i] && i + j < nums.size(); j++) {
                minJumps[i] = min(minJumps[i], 1 + minJumps[i + j]);
            }
        }
        return minJumps[0];
    }
};
