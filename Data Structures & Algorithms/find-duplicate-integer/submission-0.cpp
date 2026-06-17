class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++) {
            if(map.contains(nums[i])) return nums[i]; 
            map[nums[i]]++;
        }
        return 0;
    }
};
