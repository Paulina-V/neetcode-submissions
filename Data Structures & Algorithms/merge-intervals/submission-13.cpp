class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        sort(intervals.begin(), intervals.end(), 
        [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        // start and end holds the interval that's currently being built
        int startVal = intervals[0][0];
        int endVal = intervals[0][1];
        //cout << "start: startval=" << startVal;
         //       cout << " endval=" << endVal << "\n";
        for(int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= endVal) {
                // need to merge
                //cout << "merged: startval=" << startVal << " endval=" << endVal;
                endVal = max(intervals[i][1], endVal);
                //startVal = min(intervals[i][0], startVal);
                //cout << "merged: startval=" << startVal;
                //cout << " endval=" << endVal;
            } else {
                cout << "ekse";
                ret.push_back({startVal, endVal});
                startVal = intervals[i][0];
                endVal = intervals[i][1];
            }
        }
        ret.push_back({startVal, endVal});
        return ret;

    }
};
