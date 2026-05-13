class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (string s : strs){
            vector<int> count(26, 0);
            for(char c : s){
                count[c-'a']++;
            }
            string key = "";
            for(int i : count){
                key += '#' + to_string(i);
            }

            groups[key].push_back(s);
        }
        vector<vector<string>> result;
        for (auto& pair : groups){
            result.push_back(pair.second);
        }
        return result;
    }
};
