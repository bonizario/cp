class Solution {
   public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (citations[mid] >= n - mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return min(n - left, citations[left]);
    }
};
