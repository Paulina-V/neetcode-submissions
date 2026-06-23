class Solution {
private:
    priority_queue<pair<int, vector<int>>> kItems;

public:
    vector<vector<int>> ret;

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for(auto& p : points) {
            if(kItems.size() < k) {
                kItems.push({oDist(p[0], p[1]), p});
            } else {
                pair<int, vector<int>> top = kItems.top();
                int pDist = oDist(p[0],p[1]);
                if(top.first > pDist) {
                    kItems.pop();
                    kItems.push({pDist, p});
                }
            }
        }
        for(int i = 0; i < k; i++ ) {
            pair<int, vector<int>> top = kItems.top();
            ret.push_back(top.second);
            kItems.pop();
        }

        return ret;
    }

    int oDist(int x, int y) {
        return x*x + y*y;
    }

    
};
