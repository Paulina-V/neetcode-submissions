class Solution {
private: 
    int minK = INT_MAX;
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // time that it takes for pile[i] at rate k is (pile[i] + k - 1) / k;
        // at the speed k = max(piles), koko will finish in piles.size() hours
        // m = largest pikle
        // n = number of piles 

        // lower = 1, upper = max(piles)
        int lower = 1;
        int upper = 0;

        for(int p : piles) {
            upper = max(upper, p);
        }
        while (lower <= upper) {
            int currTestK = lower + (upper - lower) / 2;
            int kokoRet = kokoDone(currTestK, piles, h);
            cout << "upper: " << upper << " lower: " << lower << " currTestK: " << currTestK << " kokoRet: " << kokoRet << " minK: " << minK << "\n";
            if(kokoRet == 0) { // did not finish, need to increase k
                lower = currTestK + 1;
            } else { // finished, decrease k
                upper = currTestK - 1;
            }
        }
        return minK;
    }
    int kokoDone(int currTestK, vector<int> piles, int h) {
        int timeNeeded = 0;
        for (int p : piles) {
            timeNeeded += (p + currTestK - 1) / currTestK;
        }
        if(timeNeeded <= h) {
            minK = min(minK, currTestK);
            return 1;
        }
        return 0;
    }

};
