class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int c = 0, r = 0;
        int tLim = 0, rLim = matrix[0].size() - 1, bLim = matrix.size() - 1, lLim = 0;

        // while (tLim != bLim && lLim! = rLim) 
        // insert from matrix[lLim] to matrix[rLim] then increment tLim
        // insert from matrix[tLim] to matrix[bLim] then increment rLim
        // insert from matrix[rLim] to matrix[lLim] then increment bLIm
        // insert from matrix[bLim] to matrix[tLim] then increment lLim
        
        while (tLim <= bLim && lLim <= rLim) {
    for (int i = lLim; i <= rLim; i++) ret.push_back(matrix[tLim][i]);
    tLim++;

    for (int i = tLim; i <= bLim; i++) ret.push_back(matrix[i][rLim]);
    rLim--;

    if (tLim <= bLim) {                     // if still a distinct left col
        for (int i = rLim; i >= lLim; i--) ret.push_back(matrix[bLim][i]);
        bLim--;
    }

    if (lLim <= rLim) {                   // if still a distinct left col
        for (int i = bLim; i >= tLim; i--) ret.push_back(matrix[i][lLim]);
        lLim++;
    }
}
return ret;
    }
};
