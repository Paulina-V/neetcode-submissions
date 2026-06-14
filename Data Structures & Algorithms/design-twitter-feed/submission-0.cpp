class Twitter {
    int timeStamp = 0;
    unordered_map<int, vector<pair<int, int>>> tweetMap; // <userId, vector<pair<timeStamp, tweetId>>, count tracks order of tweets
    unordered_map<int, unordered_set<int>> followMap; // <userId, followeeIds (who userId follows)> 
    
public:
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({timeStamp, tweetId});
        timeStamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ret;
        // max-heap of {time, tweetId, userId, index in that user's tweet list}
        priority_queue<vector<int>> maxHeap;
        
        followMap[userId].insert(userId);

        for(int followeeId : followMap[userId]){ // look thru all of userId's followers
            if (!tweetMap.contains(followeeId)) continue; // followeeId is not a followee
            int index = tweetMap[followeeId].size() - 1; // get index of most recent tweet
            pair<int, int> tweet = tweetMap[followeeId][index]; // timeStamp, tweetId
            maxHeap.push({tweet.first, tweet.second, followeeId, index - 1});
        }

        while (!maxHeap.empty() && ret.size() < 10) {
            auto top = maxHeap.top();
            maxHeap.pop();
            int timeStamp = top[0];
            int tweetId = top[1];
            int followeeId = top[2];
            int index = top[3];
            ret.push_back(tweetId);
            if(index >= 0) {
                pair<int, int> tweet = tweetMap[followeeId][index]; // timeStamp, tweetId
                maxHeap.push({tweet.first, tweet.second, followeeId, index - 1});
            }
        }
        return ret;
    }

    
    void follow(int followerId, int followeeId) {
       followMap[followerId].insert(followeeId); 
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        followMap[followerId].erase(followeeId);
    }


};
