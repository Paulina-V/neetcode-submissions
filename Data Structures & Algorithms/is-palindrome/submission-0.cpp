class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size();
        while (l < r){
            while(l < r && !isalnum(s[l])) {
                l++;
            }
            while(l < r && !isalnum(s[r])) {
                r--;
            }
            if(tolower(s[l]) != tolower(s[r])) {
                cout << s[l];
                cout << s[r];
                cout << l;
                cout << r;
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
