class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ret;
        unordered_set<int> pacific;
        unordered_set<int> atlantic;
        queue<pair<int, int>> pq;
        queue<pair<int, int>> aq;
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int numCols = heights[0].size();
        for (int c = 0; c < numCols; c++) {
            for (int r = 0; r < heights.size(); r++) {
                if (r == 0 || c == 0) { 
                    pacific.insert(r*numCols + c);
                    pq.push({r, c});
                }
                if (c == numCols - 1 || r == heights.size() - 1) {
                    atlantic.insert(r*numCols + c);
                    aq.push({r, c});

                }
                
            }
        }
        
        while (pq.size() != 0) {
            // pacific 
            pair<int, int> pacificFront = pq.front();
            pq.pop();
            
            int pR = pacificFront.first;
            int pC = pacificFront.second;
            for (pair<int, int> d : directions) {
                int newPR = pR + d.first;
                int newPC = pC + d.second;
                if (newPR >= 0 && newPC >= 0 && newPR <= heights.size() - 1 && newPC <= heights[0].size() - 1) { // in bounds
                    if (heights[newPR][newPC] >= heights[pR][pC] && !pacific.contains(newPR * numCols + newPC)) {
                        pq.push({newPR, newPC});
                        pacific.insert(newPR * numCols + newPC);
                    }
                }
            }
        }

        while(aq.size() != 0) {
            // atlantic 
            pair<int, int> atlanticFront = aq.front();
            aq.pop();
            
            int aR = atlanticFront.first;
            int aC = atlanticFront.second;
            for (pair<int, int> d : directions) {
                int newAR = aR + d.first;
                int newAC = aC + d.second;
                if (newAR >= 0 && newAC >= 0 && newAR <= heights.size() - 1 && newAC <= heights[0].size() - 1) { // in bounds
                    if (heights[newAR][newAC] >= heights[aR][aC] && !atlantic.contains(newAR * numCols + newAC)) {
                        aq.push({newAR, newAC});
                        atlantic.insert(newAR * numCols + newAC);
                    }
                }
            }
        }
        for (int item : pacific) {
            if(atlantic.contains(item)) {
                ret.push_back({item / numCols, item % numCols});
            }
        }
        return ret;
        // if a cell is in the queue, it means that it touches the ocean of the queue that it's in
            // for the cells that are popped off, push the neighbors on (as long as the neighbors are in bounds);
            // at time of being pushed onto the queue, check if it's in the other ocean's set
    }
        
};
