class Solution {
public:
    int prev = 1;
    int fartherprev = 2;
    int currCalc = 3;
    int climbStairs(int n) {
        if (n <= 2) return n;
        while (n != currCalc) {
            if (currCalc % 2 == 1) { // odd
                prev = prev + fartherprev;
            } else {
                fartherprev = prev + fartherprev;
            }
            currCalc++;
        }

        return fartherprev + prev ;
    }
};
