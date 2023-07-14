class Solution {
   public:
    int arrangeCoins(int n) {
        // sn = (a1 + an)*n/2
        // sn = (1  +  n)*n/2
        // n = 4 and beyond always yields k < n / 2
        if (n <= 3) {
            return n == 3 ? 2 : 1;
        }
        long long left = 1, right = n / 2;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (mid * (mid + 1) / 2 >= n) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return (left * (left + 1) / 2 > n ? left - 1 : left);
    }
};
