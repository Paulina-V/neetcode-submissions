class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];

        int left = 0;
        int right = 1;
        int maxSum = nums[0];
        int curr = 0;
        int sum = 0;
        while(left < nums.size() && left < right && curr < nums.size()){
                sum += nums[curr];
                if (sum >= 0){
                    maxSum = max(sum, maxSum);
                    right++;
                    curr++;
                    maxSum = max(sum, maxSum);

                } else{
                    left = right;
                    curr = left;
                    right++;
                    maxSum = max(sum, maxSum);
                    sum = 0;

                }

        }
        return maxSum;
    }
};
