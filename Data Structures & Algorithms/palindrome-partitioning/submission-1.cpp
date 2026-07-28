class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> curr;

        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        for(int j = 0; j < n; j++) {
            dp[j][j] = true;
        }
        for (int len = 2; len <= n; len++) {
            for(int j = 0; j + len - 1 < n; j++) {
                int i = j + len - 1;
                if (s[j] == s[i]) {
                    if (len == 2) {
                        dp[j][i] = true;
                    } else {
                        dp[j][i] = dp[j+1][i-1];
                    }
                }
            }
        }
        helper(0, s, curr, ret);
        return ret;
    }

    void helper (int startIndex, string s, vector<string>& curr, vector<vector<string>>& ret) {
        if (startIndex == s.length()) {
            ret.push_back(curr);
            return;
        }

        for (int i = startIndex; i < s.length(); i++) {
            if(isPalindrome(s, startIndex, i)) {
                // push, recurse, pop
                curr.push_back(s.substr(startIndex, i - startIndex + 1));
                helper(i + 1, s, curr, ret);
                curr.pop_back();
            }
        }
 
    }

    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        
        return true;
    }
};
