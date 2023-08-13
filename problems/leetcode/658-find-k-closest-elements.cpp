class Solution {
    // Time Complexity: O(log(N - K)) to binary research and find result
    // Space Complexity: O(K) to create the returned list.
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - k;
        while (left < right) {
            int mid = left + (right - left) / 2;
            // sliding window arr[mid] ~ arr[mid + k]

            // case 1: x - A[mid] < A[mid + k] - x, need to slide the window to the left
            // ----x----A[mid]----------------------A[mid + k]---------

            // case 2: x - A[mid] < A[mid + k] - x, need to slide the window to the left
            // ---------A[mid]----x-----------------A[mid + k]---------

            // case 3: x - A[mid] > A[mid + k] - x, need to slide the window to the right
            // ---------A[mid]-----------------x----A[mid + k]---------

            // case 4: x - A[mid] > A[mid + k] - x, need to slide the window to the right
            // ---------A[mid]----------------------A[mid + k]----x----

            if (x - arr[mid] <= arr[mid + k] - x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};
