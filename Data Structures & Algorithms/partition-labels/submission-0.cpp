class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_set<char> openSet;
        vector<int> ret;
        int subsetSize = 0;

        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        for (char c : s) {
            freq[c]--; // decremenet c's freq bc we got here
            subsetSize++;

            if (freq[c] == 0) {
                openSet.erase(c);
            } else {
                openSet.insert(c);
            }

            if (openSet.size() == 0) { // new substring
                ret.push_back(subsetSize);
                subsetSize = 0;
            }
        }
        return ret;
    }
};
