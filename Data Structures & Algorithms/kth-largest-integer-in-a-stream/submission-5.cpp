class KthLargest {
    // want to make a priority queue that stores the streamed values from smallest -> largest

private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int kVal;
public:
    KthLargest(int k, vector<int>& nums) {
        kVal = k;
        for(int n : nums) {
            minHeap.push(n);
            if (minHeap.size() > kVal) {
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > kVal) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};
