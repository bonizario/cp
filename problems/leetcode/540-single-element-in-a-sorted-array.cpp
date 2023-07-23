class Solution {
   public:
    int isEven(int n) {
        return (n & 1) == 0;
    }

    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if ((mid > 0 && nums[mid] == nums[mid - 1] && isEven(n - mid - 1)) ||
                (mid < n - 1 && nums[mid] == nums[mid + 1] && isEven(n - mid))) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (left == 0 || left == n - 1) {
            return nums[left];
        }
        return nums[left - 1];
    }
};
