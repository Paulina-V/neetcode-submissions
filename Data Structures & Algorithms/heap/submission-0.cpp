class MinHeap {
public:
    vector<int> heap;
    MinHeap() {
        heap.push_back(0);
    }
    int dummy = 1;
    void push(int val) { // adding a value
        heap.push_back(val); // put val at the end
        bubbleUp(heap.size()-1); // fix the heap order
    }

    int pop() { // remove and return the min value
        if(heap.size() - dummy == 0) return -1;
        int ret = heap[1]; // get the return value
        heap[1] = heap.back(); // put the last val into the root position
        heap.pop_back(); //remove the last val
        bubbleDown(1); // fix the heap order
        return ret;
    }

    int top() { // return but don't remove the min value
        if(heap.size() - dummy == 0) return -1;
        return heap[1]; //cuz the min value is always on top
    }

    void heapify(const vector<int>& arr) { // build a min heap from arr
        heap.clear();
        heap.push_back(0); // insert a dummy
        heap.insert(heap.end(), arr.begin(), arr.end()); // copy stuff over
        
        // start at last non leaf and bubble the item down
        for(int i = (heap.size() - dummy)/2; i >= 1; i--){
            bubbleDown(i);
        }
    }

    void bubbleDown(int index){ // bubbles down int n until it is less than both child nodes
        int leftIndex = index * 2;
        int rightIndex = index * 2 + 1;
        
        while(leftIndex < heap.size()){
            if(rightIndex < heap.size() && heap[rightIndex] <= heap[leftIndex] && heap[index] > heap[rightIndex]){
                swap(heap[index], heap[rightIndex]);
                index = rightIndex;
            } else if(heap[index] > heap[leftIndex]){ // swap with left
                swap(heap[index], heap[leftIndex]);
                index = leftIndex;
            } else{ 
                break;
            }
            leftIndex = index * 2;
            rightIndex = index * 2 + 1;

        }
    }

    void bubbleUp(int index){ // bubbles up int n until it is less than both child nodes
        while(index > 1){
            int parent = index/2;
            if(heap[index] < heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else{
                break;
            }
        }
    }
};
