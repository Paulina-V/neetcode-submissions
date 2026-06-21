class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        int house1 = max(nums[0], nums[1]); // nums[i-1] last one
        int house2 = nums[0]; // nums[i-2] last last one

        nums[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            int temp = max(house2 + nums[i], house1);
            house2 = house1;
            house1 = temp;
            nums[i] = temp;
        }
        return nums[nums.size() - 1];
    }
};
