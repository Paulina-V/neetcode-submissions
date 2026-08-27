class TimeMap {
private: 
    unordered_map<string, vector<pair<int, string>>> myMap;
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        myMap[key].push_back({timestamp, value});
    }
    
    
    string get(string key, int timestamp) {
        vector<pair<int, string>> valVect = myMap[key];
        string maxTime = "";
        int l = 0;
        int r = valVect.size() - 1;
        while (l <= r){
            int mid = l + (r - l) / 2;
            if(valVect[mid].first == timestamp) { // hit it
                return valVect[mid].second;
            } else if (valVect[mid].first < timestamp) {
                maxTime = valVect[mid].second;
                l = mid + 1;
            } else { // valVect[mid].first > timestamp
                r = mid - 1;
            }
        }
        // now we got to the point that it doesn't exist, so we gotta return the next biggest
        return maxTime;
    }
};
