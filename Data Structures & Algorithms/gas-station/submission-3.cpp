class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
       
        int currTank = 0;
        int totalTank = 0;
        int starting = 0;
        for (int i = 0; i < n; i++) {
            totalTank += gas[i] - cost[i];
            currTank += gas[i] - cost[i];
            if (currTank < 0) { // every station from current starting up to i cannot be the start
                starting = i + 1;
                currTank = 0;
            }
        }
        
        
        return totalTank < 0 ? -1 : starting;
    }
};
