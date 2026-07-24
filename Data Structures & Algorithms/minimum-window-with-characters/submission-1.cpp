class Solution {
public:
    string minWindow(string s, string t) { // fit t inside s
        if (t.length() > s.length()) return ""; // auto return if the t is bigger than s

        unordered_map<char, int> countT, window; // countT holds info ab t, window holds info about what's currently in the sliding window
        for (char c : t) countT[c]++; // loop thru everything in T and populate what characters t needs

        int have = 0; // have holds a count of how many uniqe characters are currently satisfied
        int need = countT.size(); // number of unique characters we need to satisfy

        int left = 0; // left = where the window starts 
        int minLen = INT_MAX; // size of the minimum length
        int minStart = 0; // start of the substring with minimum length

        for (int right = 0; right < s.size(); right++) { // loop through big string
            char c = s[right]; // c is the current character 
            window[c]++; // add c counts into the info about the current window

            if (countT.count(c) && window[c] == countT[c]) { // if this character now satisfies its required count
                have++; // increase what we have
            }
            
            while (have == need) { // increment the left pointer while we have everything we need
                int windowLen = right - left + 1; // window length calc
                if (windowLen < minLen) { // if the windowLength currently is good, then we do some replacement stuff 
                    minLen = windowLen;
                    minStart = left;
                }

                char leftChar = s[left]; // left char is the character at the start of the wiwnodw
                window[leftChar]--; // decreement the number of occurrences of this character because we're about to remove it
                if (countT.count(leftChar) && window[leftChar] < countT[leftChar]) { // if the window has less of the leftChar than we need, then we gotta decreemet the number we have
                    have--;
                }
                left++; // move the pointer now
            }
        }
        if (minLen == INT_MAX) {
            return "";
        } 
        
        return s.substr(minStart, minLen);
    }
};
