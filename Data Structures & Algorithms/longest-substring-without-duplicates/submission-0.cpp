class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int > currChars; // char, index
        int left = 0; // inclusive index of the starter
        int maxLength = 0;
        for(int i = 0; i < s.length(); i++) {
            if(currChars.contains(s[i]) && currChars[s[i]] < i && currChars[s[i]] >= left){
                left = currChars[s[i]] + 1; // index of the repeater
            }
            currChars[s[i]] = i;
            maxLength = max(maxLength, i - left + 1);

        }
        return maxLength;
    }
};
