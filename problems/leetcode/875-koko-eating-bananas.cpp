class Solution {
   public:
    bool is_feasible(vector<int>& piles, int h, int speed) {
        int total_hours = accumulate(piles.begin(), piles.end(), 0,
                                     [&](int hours, const int p) { return hours + ((p - 1) / speed + 1); });
        return total_hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (is_feasible(piles, h, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
