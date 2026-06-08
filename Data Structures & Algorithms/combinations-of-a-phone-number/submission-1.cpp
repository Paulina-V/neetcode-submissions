class Solution {
public:
    vector<string> mapping = {
                "",     // 0
                "",     // 1
                "abc",  // 2
                "def",  // 3
                "ghi",  // 4
                "jkl",  // 5
                "mno",  // 6
                "pqrs", // 7
                "tuv",  // 8
                "wxyz"  // 9
            };
    vector<string> letterCombinations(string digits) {
        
        vector<string> ret;

        if(digits.length() == 0) return ret;
        helper(ret, "", digits, 0);
        
        return ret;
        
    }

    void helper(vector<string>& ret, string currCombo, string digits, int digitIndex){
        if(digits.length() == currCombo.length()) {
            ret.push_back(currCombo);
            return;
        }
        char currDigit = digits[digitIndex];
        string fullLetterMappingString = mapping[currDigit-'0'];
        for (char c : fullLetterMappingString) {
            currCombo.push_back(c);
            helper(ret, currCombo, digits, digitIndex + 1);
            currCombo.pop_back();
        }

    };
};