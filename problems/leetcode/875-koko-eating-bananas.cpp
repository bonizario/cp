class Solution {
   public:
    bool feasible(const vector<int>& piles, int speed, int available_hours) {
        int required_hours = accumulate(piles.begin(), piles.end(), 0, [&](int hours, int pile) {
            return hours + ((pile - 1) / speed + 1);
        });
        return required_hours <= available_hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (feasible(piles, mid, h)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
