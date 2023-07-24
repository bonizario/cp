class Solution {
   public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size(), left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid > 0 && arr[mid] <= arr[mid - 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left - 1;
    }
};
