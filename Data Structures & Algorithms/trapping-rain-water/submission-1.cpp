class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefixMax(height.size() + 1, 0);
        vector<int> suffixMax(height.size() + 1, 0);
        int water = 0;

        for(int i = 1; i < height.size(); i++) {
            prefixMax[i] = max(height[i - 1], prefixMax[i - 1]);

        }
        for(int i = height.size() - 2; i >= 0; i--) {
            suffixMax[i] = max(height[i + 1], suffixMax[i + 1]);
        }
        for(int i = 0; i < height.size(); i++) {            
            water += max(0, min(prefixMax[i], suffixMax[i]) - height[i]);
        }
        return water;
    }
};
// hint 1: How can we determine the amount of water 
//         that can be trapped at a specific position 
//         in the array? 
//           - the amount of water stored = min(leftH, rightH) - height[i]

