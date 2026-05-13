#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (string s : strs) {
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            map[sorted].push_back(s);
            //now the map is holding all the lists
        }
        vector<vector<string>> ret;
        for (auto& thing : map) {
            ret.push_back(thing.second);
        }
        return ret;
    }
};
