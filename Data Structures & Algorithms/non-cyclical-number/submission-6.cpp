class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seenNums;
        while(n != 1) {
            for (int n : seenNums);
    
            int sum = getSum(n);
            if (seenNums.contains(sum)) return false;
            seenNums.insert(sum);
            n = sum;
        }
        return true;
    }
    int getSum(int num) {
        int sum = 0;
        while (num > 9) {
            int digit = num % 10;
            sum += (digit * digit);
            num = num / 10;
        }
        sum += num * num;
        return sum;
    }
};
