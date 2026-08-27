class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        while(l < r){
            int currSum = numbers[r] + numbers[l];
            if (currSum == target) {
                return {l+1, r+1};
            }
            if (currSum > target) {
                r--;
            } else if (currSum < target) {
                l++;
            }
        }
    }
};
