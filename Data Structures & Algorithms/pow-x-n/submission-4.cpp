class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n;
        if (x == 1) return x;
        if (x == -1) return (nn % 2 == 0) ? x * x : x;
        double ret = 1;

        if (nn > 0) {
            for (int i = 0; i < nn; i++) {
                ret *= x;
            }
        } else {
            for (int i = 0; i < -nn; i++) {
                ret /= x;
                if (ret <= 0.0000000000000000001) return 0;
            }
        }
        
        return ret;
    }
};
