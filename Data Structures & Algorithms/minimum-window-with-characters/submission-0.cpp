class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) return "";

        unordered_map<char, int> countT, window;
        for (char c : t)countT[c]++;

        int have = 0;
        int need = countT.size();

        int left = 0;
        int minLen = INT_MAX;
        int minStart = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c]++;

            if (countT.count(c) && window[c] == countT[c]) {
                have++;
            }
            
            while (have == need) {
                int windowLen = right - left + 1;
                if (windowLen < minLen) {
                    minLen = windowLen;
                    minStart = left;
                }

                char leftChar = s[left];
                window[leftChar]--;
                if (countT.count(leftChar) && window[leftChar] < countT[leftChar]) {
                    have--;
                }
                left++;
            }
        }
        if (minLen == INT_MAX) {
            return "";
        } 
        
        return s.substr(minStart, minLen);
    }
};
