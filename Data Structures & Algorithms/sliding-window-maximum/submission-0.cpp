class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> output;
        int l = 0, r = 0;
        deque<int> dq; 
        
        while (r < nums.size()) {
            while(dq.size() > 0 && nums[r] > nums[dq.back()]) { // make sure no smaller values are smile
                dq.pop_back();
            }
            dq.push_back(r);
            if (dq.front() < l) {
                dq.pop_front();
            } 

            if(r + 1 >= k) {
                output.push_back(nums[dq.front()]);
                l++;
            }
            r++;
        }
        return output;
    }
};
/*
    deque solution:
        - have a dequeue that is storing the indecies of the values in ur window right now
        - initialize left and right pointers that will correspond to the start and end of the current window ur looking at
        - use the right pointer to loop through nums, and while it's still in bounds
            - add the number at the right pointer to the back of the queue if it's smaller than the current
              if not, then remove the values that are there until the one that ur adding isn't bigger anymore
            - pop from the front if the left pointer (where window should be) is bigger than where the window in the dq actually starts
            - if the index of the dq's end is bigger than what the window should be, add the biggest thing to the output and increment the left side
            - move thr right 
    learnings: 
        - a deque is a double ended queue where from both ends you can push and pop 
          so in a sense it's like a stack as well depending on how u wanna use it
*/
