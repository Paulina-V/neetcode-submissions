class Solution {
public:

    string encode(vector<string>& strs) {
        string str;
        for(auto& s : strs){
            str.append(to_string(s.size()));
            str.append("#");
            str.append(s);
        }
        return str;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        for(int i = 0; i < s.length(); i++) {
            int tempNum = 0;
            while (s[i] != '#'){
                tempNum = tempNum * 10 + (s[i] - '0');
                i++;
            }
            strs.push_back(s.substr(i + 1, tempNum));
            i += tempNum;
            tempNum = 0;

        }
        return strs;
    }
};
