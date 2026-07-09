class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int maxArea = 0;
        int maxL = 0;
        int maxR = 0;
        while(l != r){
            int area = (r-l) * min(heights[l], heights[r]);
            if(area > maxArea){
                maxArea = area;
                maxL = l;
                maxR = r;
            }
            if(heights[l] < heights[r]){
                l++;
            } else {
                r--;
            }
        }
        return maxArea;
    }
};
