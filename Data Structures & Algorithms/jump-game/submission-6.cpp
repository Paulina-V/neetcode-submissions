class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0) {
            int minSize = 1;
            bool canJump = (nums[i] >= minSize) ? true : false;
            if (canJump) {
                i--;
            } else {
                while (canJump == false) {
                    cout << "a";
                    minSize++;
                    i--;
                    if(i < 0) return false;
                    canJump = (nums[i] >= minSize) ? true : false;
                }
                i--;
            }
        }
        return true;
    }
};
