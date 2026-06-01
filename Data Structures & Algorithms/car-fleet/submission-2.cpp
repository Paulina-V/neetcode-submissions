class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        int numCars = position.size();
        int fleets = numCars;
        for(int i = 0; i < numCars; i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end());
        double lastCarTime = (double)(target - cars[numCars - 1].first) / cars[numCars - 1].second;
        for(int i = numCars - 2; i >= 0; i--) {
            double thisCarTime = (double)(target - cars[i].first)/cars[i].second;
            if(thisCarTime <= lastCarTime) {
                fleets--;
            } else {
                lastCarTime = thisCarTime;
            }
        }
        return fleets;
    }
};