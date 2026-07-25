class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seenNums;
        while(n != 1) {
            cout << "seenNums";
            for (int n : seenNums) cout << n << " ";
            cout << "\n\n";
            
            int sum = 0;
            cout << "initial n: " << n << "\n";
            cout << "first digit : " << n % 10 << "\n\n";

            while (n > 9) {
                int digit = n % 10;
                sum += (digit * digit);
                n = n / 10;
                cout << "digit: " << digit << " \n";
                cout << "n left: " << n << " \n";
                cout << "sum: " << sum << " \n";
                cout << "\n";
            }
            sum += n*n;
            if (seenNums.contains(n)) return false;
            seenNums.insert(sum);
            cout << "sum inserted" << sum << " ";
            n = sum;
        }
        return true;
    }
};
