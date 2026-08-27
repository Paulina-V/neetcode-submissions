class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       // return true if nums[i] = -(nums[j] + nums[k]) 
       // - nums[i] = nums[j] + nums[k]
       // for each index i, calculate all j and k pairs
       // 
       std::sort(nums.begin(), nums.end());
       vector<vector<int>> ret;

        for(int i = 0; i < nums.size() - 2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    ret.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while (j<k && nums[j] == nums[j-1]){
                        j++;
                    }
                } else if(sum < 0){
                    j++;
                } else {
                    k--;
                }
            }
        }
        return ret;
    }

};
