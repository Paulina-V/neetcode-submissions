class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> count;
        vector<int> res;

        int length = S.length();

        // Store frequencies as negative values.
        for (char c : S) {
            count[c]--;
        }

        int i = 0;
        int curLen = 0;
        int open = 0;

        while (i < length) {
            char c = S[i];

            if (count[c] < 0) {
                // First occurrence in the current scan.
                open++;

                // Convert negative frequency into remaining occurrences.
                count[c] = -count[c] - 1;
            } else {
                // Consume another occurrence.
                count[c]--;
            }

            curLen++;

            // No more occurrences of this character remain.
            if (count[c] == 0) {
                open--;
            }

            if (open == 0) {
                res.push_back(curLen);
                curLen = 0;
            }

            i++;
        }

        return res;
    }
};