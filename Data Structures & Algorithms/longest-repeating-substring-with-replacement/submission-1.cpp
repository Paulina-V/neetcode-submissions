class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freqs;
        int left = 0;
        int maxFreq = 0;
        int maxLength = 0;
        for(int right = 0; right < s.length(); right++) {
            freqs[s[right]]++;
            maxFreq = max(maxFreq, freqs[s[right]]);
            if(right - left + 1 > k + maxFreq) {
                freqs[s[left]]--;
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};