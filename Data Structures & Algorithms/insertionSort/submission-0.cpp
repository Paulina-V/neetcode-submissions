// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> res;
        for (int j = 0; j < pairs.size(); j++) {
            int i = j - 1;
            while(i >= 0 && pairs[i + 1].key < pairs[i].key) {
                Pair temp = pairs[i];
                pairs[i] = pairs[i + 1];
                pairs[i + 1] = temp;
                i--;
            }
            res.push_back(pairs);

        }
        return res;
    }
};
