class Solution {
   public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        if (nums[right] > nums[left]) {
            return nums[left];
        }
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[right]) {
                right = mid;
            } else if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                if (nums[right - 1] > nums[right]) {  // right > 0 always
                    left = right;
                    break;
                }
                right -= 1;
            }
        }
        return nums[left];
    }
};
