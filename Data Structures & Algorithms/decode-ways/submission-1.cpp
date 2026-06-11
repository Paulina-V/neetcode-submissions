class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        vector<int> nums (s.size(), 0);

        nums[0] = 1;
        for (int i = 1; i < s.size(); i++) {
            // can stand alone
            if (s[i] != '0') {
                nums[i] += nums[i - 1];
            }
            // can form big number
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                if (i - 2 >= 0) {
                    nums[i] += nums[i - 2];
                } else {
                    // i == 1: the "two back" base is the empty prefix, 1 way
                    nums[i] += 1;
                }
            }
            
        }
        return nums[s.size() - 1];
    }

    void printall(vector<int> nums) {
        for (int n : nums) {
            cout << n << " ";
        }
        cout << "\n";
    }
};
