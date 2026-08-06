class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        int windowSize = s1.length();
        vector<int> windowOccurences (26, 0);
        vector<int> s1Occurences (26, 0);
        for(char s : s1){ //look thru short word map
            s1Occurences[s - 'a']++;
        }
       
        for(int i = 0; i < s1.length(); i++) { // get the first window of the long word
            windowOccurences[s2[i] - 'a']++;

        }
        if(windowOccurences == s1Occurences) {
                return true;
            }
        for(int i = s1.length(); i < s2.length(); i++) {
            windowOccurences[s2[i - s1.length()] - 'a']--;
            windowOccurences[s2[i] - 'a']++;
            if(windowOccurences == s1Occurences) {
                return true;
            }
        }
        
        return false;
    }
};
