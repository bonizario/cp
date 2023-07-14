class Solution {
   public:
    bool isPerfectSquare(int num) {
        long long left = 1, right = num;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (mid * mid >= num) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left * left == num;
    }
};
