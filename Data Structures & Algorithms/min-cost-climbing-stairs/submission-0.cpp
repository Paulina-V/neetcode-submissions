class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int endIndex = cost.size();
        cost.push_back(0);
        for (int i = endIndex - 2; i >= 0; i--) {
            int option1 = cost[i] + cost[i + 1];
            int option2 = cost[i] + cost[i + 2];
            cost[i] = min(option1, option2);
            printAll(cost);
        }
        return min(cost[0], cost[1]);
    }
    void printAll(vector<int>&cost){
        for(int i : cost) {
            cout << i << " ";
        }
        cout << "\n";
    }
};
