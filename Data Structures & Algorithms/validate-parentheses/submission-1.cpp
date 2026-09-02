class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++) {
            char curr = s[i];
            if(curr == '[' || curr == '(' || curr == '{') {
                st.push(curr);
            } else if (st.empty() ||
                        (st.top() == '[' && curr != ']') || // mismatch
                        (st.top() == '(' && curr != ')') ||
                        (st.top() == '{' && curr != '}')) {
                return false;
            } else {
                st.pop();
            }
        }
        return st.empty();
    }
};
