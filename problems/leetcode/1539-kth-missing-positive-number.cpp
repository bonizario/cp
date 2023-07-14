class Solution {
   public:
    int missing(vector<int>& arr, int index) {
        return arr[index] - index - 1;
    }

    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (missing(arr, mid) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        // if (left == 0) {
        //     return arr[left] > k ? k : arr[left] + k - missing(arr, left);
        // }
        // return arr[left - 1] + k - missing(arr, left - 1);

        // simplification:
        // arr[left-1] + k - arr[left-1] + (left - 1) + 1
        // equals to:
        // left + k
        return left + k;
    }
};
