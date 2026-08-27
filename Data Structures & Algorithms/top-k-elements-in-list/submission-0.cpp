class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        vector<vector<int>> freq(nums.size() + 1);
        unordered_map<int, int> ct; //number, freq

        for(int n : nums) { // count the frequencies by number
            ct[n]++;
        }

        for (auto& item : ct) { // hold the numbers in sets by frequency
            int frequency = item.second;
            int number = item.first;
            freq[frequency].push_back(number);
        }

        for(int i = nums.size(); i >= 0; i--) { // go through the most frequent item and add to result to print
            for(int num : freq[i]) {
                result.push_back(num);
                if(result.size() == k){
                    return result;
                }
            }
        }
        return result;
    }
};
