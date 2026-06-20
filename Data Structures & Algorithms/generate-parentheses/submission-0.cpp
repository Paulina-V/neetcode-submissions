class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string curr;
        dfs(curr, n, 0, 0, ret);
        return ret;
    }
    void dfs(string curr, int n, int openCt, int closedCt, vector<string>& ret) {
        if (curr.length() == 2 * n) {
            ret.push_back(curr);
            return;
        }
        if (openCt < n) {
            curr.push_back('(');
            dfs(curr, n, openCt + 1, closedCt, ret);
            curr.pop_back();
        }
        if (closedCt < openCt) {
            curr.push_back(')');
            dfs(curr, n, openCt, closedCt + 1, ret);
            curr.pop_back();
        }
    }
    
};
