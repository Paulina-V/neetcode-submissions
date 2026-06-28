class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

public:
    KthLargest(int kValue, vector<int>& nums) {
        k = kValue;
        for (int num : nums) {
            minHeap.push(num); // add each number into the min
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }

    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};
// minheap is a pq that keeps the smallest element at the top 