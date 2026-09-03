class Solution {
public:
    vector<int> dp; // -1 = not visited, 1 = ok , 0 = not ok

    bool wordBreak(string s, vector<string>& wordDict) {
        dp = vector<int>(s.size(), -1);
        return dfs(0, s, wordDict); // starts recursion from index 0
    }
    bool dfs(int i, string s, vector<string>& wordDict) { // check if substr i -> end is feasible
        if (i == s.size()) return true; // if we reached the end of the string, return true cuz all chars matched
        if (dp[i] != -1) {
            if (dp[i] == 1) return true;
            return false;
        }
        for (string w : wordDict) { // look at every word in dictionary and see if any of them can start at i
            if (w.size() + i <= s.size() && s.substr(i, w.size()) == w) { // if the word is short enough to fit in the remaining space and the stuff that follows i is same as w
                if (dfs(i + w.size(), s, wordDict)) { // call dfs to try the rest of the word if it can bes plit well 
                    dp[i] = 1; 
                    return true;
                }
            }
        }
        dp[i] = 0;
        return false;
    }
};
