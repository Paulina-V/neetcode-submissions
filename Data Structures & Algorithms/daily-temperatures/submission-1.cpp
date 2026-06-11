class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ret(temperatures.size(), 0);
        stack<int> st;
        st.push(temperatures[0]);
        for (int i = 1; i < temperatures.size(); i++) {
            int daysBeforeCount = 0;
            while (!st.empty() && temperatures[i] > st.top()) { // today is warmer
               daysBeforeCount++;
               while(ret[i - daysBeforeCount] != 0) { daysBeforeCount++; }
               ret[i - daysBeforeCount] = daysBeforeCount;
               st.pop();
            }
            st.push(temperatures[i]);
        }
        return ret;
    }
};
