class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars(n);
        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], speed[i]};
        }
        sort(cars.begin(), cars.end());
        stack<double> fleets;
        for (int i = n - 1; i >= 0; i--) {
            double time = ((double)(target - cars[i].first)) / cars[i].second;
            if (fleets.empty() || fleets.top() < time) {
                // the current car arrives after fleets.top(), it becomes a new fleet
                fleets.push(time);
            }
        }
        return fleets.size();
    }
};
