class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> ge_left(n);   // greater or equal from left
        vector<int> ge_right(n);  // greater or equal from right
        ge_left[0] = -1, ge_right[n - 1] = n;
        for (int i = 1; i < n; i++) {
            int p = i - 1;
            while (p >= 0 && heights[p] >= heights[i]) {
                p = ge_left[p];
            }
            ge_left[i] = p;
        }
        for (int i = n - 2; i >= 0; i--) {
            int p = i + 1;
            while (p < n && heights[p] >= heights[i]) {
                p = ge_right[p];
            }
            ge_right[i] = p;
        }
        int max_area = 0;
        for (int i = 0; i < n; i++) {
            max_area = max(max_area, heights[i] * (ge_right[i] - ge_left[i] - 1));
        }
        return max_area;
    }
};
