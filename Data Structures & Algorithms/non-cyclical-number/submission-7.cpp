class Solution {
public:
    bool isHappy(int n) {
        int slow = getSum(n);
        int fast = getSum(getSum(n));
        while (slow != fast) {
            if (slow == 1 || fast == 1) return true;
            slow = getSum(slow);
            fast = getSum(getSum(fast));
        }
        if (slow == 1 || fast == 1) return true;
        return false;
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
