class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        int begin_index = left;
        if (target > nums[n - 1]) {
            left = 0, right = begin_index - 1;
        } else {
            right = n - 1;
        }
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (target <= nums[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return target == nums[left] ? left : -1;
    }
};
