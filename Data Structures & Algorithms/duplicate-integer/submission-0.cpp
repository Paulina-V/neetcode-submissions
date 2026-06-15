#include <iostream>
#include <unordered_set>
#include <vector>
#include <array>

class Solution {

public:
    bool hasDuplicateOld(vector<int>& nums) {
        
        std::unordered_set<int> mySet(nums.begin(), nums.end());
        if (mySet.size() == nums.size()) {
            return false;
        } else {
            return true;
        }
    }

    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> mySet;
        for (int i = 0; i < nums.size(); i++) {
            if (mySet.insert(nums[i]).second == false) {
                return true;
            }
        }
        return false;
    }
};
