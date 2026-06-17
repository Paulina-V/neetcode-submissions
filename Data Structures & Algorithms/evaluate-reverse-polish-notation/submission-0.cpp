class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int result = 0;
        unordered_set<string> operators;
        operators.insert("+");
        operators.insert("-");
        operators.insert("*");
        operators.insert("/");

        stack<int> st;
        for (auto& t : tokens) {
            if(!operators.contains(t)) {
                st.push(stoi(t));
            } else {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if (t == "+") { st.push(a + b); }
                if (t == "*") { st.push(a * b); }
                if (t == "/") { st.push(a / b); }
                if (t == "-") { st.push(a - b); }

            }
        }
        return st.top();
    }
};
