class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int newNum = digits[n - 1] + 1; // increment last one by 1
        digits[n - 1]  = newNum;
        if (newNum <= 9) return digits;
        digits[n - 1]--;
        
        int carry = 1;
        for (int i = n - 1; i >= 0; i--) {
            int sum = digits[i] + carry;
            digits[i] = (digits[i] + carry) % 10;
            carry = sum / 10;
            if (i == 0 && carry != 0) {
                digits.insert(digits.begin(), 1); 
            }
        }
        return digits;        
    }
};
