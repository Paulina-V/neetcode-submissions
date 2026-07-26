class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seenNums;
        while(n != 1) {
            for (int n : seenNums);
    
            int sum = 0;
            while (n > 9) {
                int digit = n % 10;
                sum += (digit * digit);
                n = n / 10;
            }
            sum += n*n;
            if (seenNums.contains(n)) return false;
            seenNums.insert(sum);
            n = sum;
        }
        return true;
    }
};
