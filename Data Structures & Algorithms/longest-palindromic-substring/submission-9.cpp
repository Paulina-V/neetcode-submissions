class Solution {
public:
    string ret;
    string longestPalindrome(string s) {
        // iterate over string with index i and imagine it's the center
        // even length abba: chars i-1 and i need to be the same 
        // odd length ababa: chars i-1 and i+1 must be same
        if (s.size() == 0) return "";
        if (s.size() == 1) return s;
        ret = s.substr(0, 1);
        for (int i = 0; i < s.size(); i++) {
            string even = updateRetAtIndex(s, i, 0); // even
            string odd = updateRetAtIndex(s, i, 1); // odd
            if(even.size() > odd.size() && even.size() > ret.size()) {
                ret = even;
            }
            else if (odd.size() > ret.size()) {
                ret = odd;

            }
        }
        return ret;
    }
    
    string updateRetAtIndex(string s, int i, int rightBool) {
        int l = i;
        int r = i + rightBool;
        string returnval = s.substr(i, 1);
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            if (r - l + 1 > returnval.length()) {
                returnval = s.substr(l, r - l + 1);
            }
            l--;
            r++;
        }
        return returnval;
    }
};
