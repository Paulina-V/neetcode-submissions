class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        unordered_map <int, int> cards;
        sort(hand.begin(), hand.end());

        //cout << "hand: ";
        for (int i = 0; i < hand.size(); i++) {
            //cout << hand[i] << " ";
            cards[hand[i]]++;
        }
        //cout << "\n";
        

        int handStartVal = hand[0];
        for (int i = 0; i < hand.size() / groupSize; i++) {
            //cout << "handStartVal: " << handStartVal << "\n";
            for (int j = 0; j < groupSize; j++) {
                if (cards[handStartVal + j] < 1) { // return false if there's no more of that one
                    return false;
                }
        
                cards[handStartVal + j]--;

            }
            while(i != hand.size() / groupSize - 1 && cards[handStartVal] < 1) handStartVal++;
        }

        return true;
    }
};

