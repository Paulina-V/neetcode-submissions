/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), 
            [](const Interval& a, const Interval& b){
            return a.start < b.start;
        });
        // make a heap that stores the end times as a minheap, such that the smallest/earliest ending room comes first. 

        // loop through all the intervals/meetings
            // if the room start time > top of the heap, then it's okay
                //pop from top of heap and push this new end time in
            // else not okay
                // push this to the heap
        // return heap size
        priority_queue<int> roomsEndsMinHeap;
    
        for (int i = 0; i < intervals.size(); i++) {
            if (!roomsEndsMinHeap.empty() && intervals[i].start >= -roomsEndsMinHeap.top()) {
                roomsEndsMinHeap.pop();
            }
            roomsEndsMinHeap.push(-intervals[i].end);
        }
        return roomsEndsMinHeap.size();
    }
};


