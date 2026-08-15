class NumArray {

private: 
    vector<int> prefixes;
public:
    NumArray(vector<int>& nums) {
        prefixes.resize(nums.size());
        for(int i = 0; i < nums.size(); i++){
            if (i == 0) {
                prefixes[i] = nums[i];
            } else {
                prefixes[i] = prefixes[i-1] + nums[i];
            }

        }
    }
    
    int sumRange(int left, int right) {
        if(left <= 0) { 
            return prefixes[right]; 
        }
        return prefixes[right] - prefixes[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */