class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set numSet (nums.begin(), nums.end());
        int maxCount = 0;
        int currCount = 0;
        for (int n : nums) {
            if (!numSet.contains(n - 1)) {
                while (numSet.contains(n)) {
                    currCount++;
                    n++;
                }
                maxCount = max (maxCount, currCount);
                currCount = 0;
            }
        }
        return maxCount;
    }
};
