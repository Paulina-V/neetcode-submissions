class Solution {
private:
    priority_queue<int> maxHeap;
public:
    int lastStoneWeight(vector<int>& stones) {
        for(int s : stones) {
            maxHeap.push(s);
        }
        while(maxHeap.size() >= 2) {
            int biggest = maxHeap.top();
            maxHeap.pop();
            int secondBiggest = maxHeap.top();
            maxHeap.pop();
            if(biggest == secondBiggest) { // both destroyed

            } else if(secondBiggest < biggest) {
                maxHeap.push(biggest-secondBiggest);
            }
        }
        if(maxHeap.size() == 1) return maxHeap.top();
        return 0;
    }
};
