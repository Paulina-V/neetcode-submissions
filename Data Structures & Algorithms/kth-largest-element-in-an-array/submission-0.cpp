class Solution {
private:
    priority_queue<int, vector<int>, greater<int>> kNums;
    // greater is lower priority
    // smaller ones pop easier
public:
    int findKthLargest(vector<int>& nums, int k) {
        for(int n : nums) {
            if(kNums.size() < k) {
                kNums.push(n);
            } else {
                int smallestHeld = kNums.top();
                if(n > smallestHeld) {
                    kNums.pop();
                    kNums.push(n);
                }
            }
        }
        return kNums.top();
    }
};
