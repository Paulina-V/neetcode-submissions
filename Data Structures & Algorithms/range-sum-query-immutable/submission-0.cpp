class NumArray {
private:
    vector<int> myNums;
public:
    NumArray(vector<int>& nums) {
        myNums = nums;
    }
    
    int sumRange(int left, int right) {
        return prefix(right) - prefix(left) + myNums[right];
    }
    
    int prefix(int index){ // up to not including this index
        int sum = 0;
        for (int i = 0; i < index; i++){
            sum += myNums[i];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */