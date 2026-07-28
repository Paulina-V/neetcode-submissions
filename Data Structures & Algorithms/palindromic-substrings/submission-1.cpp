class Solution {
public:
    int countSubstrings(string s) {
        int ct = 0;
        for (int i = 0; i < s.size(); i++) {
            ct += countSubstringsAtIndex(i, s, 1); // odd
            ct += countSubstringsAtIndex(i, s, 0); // even
        }
        return ct;
    }
    int countSubstringsAtIndex(int i, string s, int oddEven) {
        int l;
        int r;
        if (oddEven == 1) {
            l = i;
            r = i; // odd = 1, even = 0
        } else {
            l = i - 1;
            r = i + oddEven;
        }
        
        int tempCt = 0;
        while (l >= 0 && r <= s.size() - 1 && s[l] == s[r]) {
            tempCt++;
            l--;
            r++;
        }
        return tempCt;
    }
};
