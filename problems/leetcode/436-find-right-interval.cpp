class Solution {
   public:
    int search(vector<vector<int>>& intervals, int n, int target) {
        int left = 0, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (target <= intervals[mid][0]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });
        vector<int> ans(n);
        for (auto& interval : intervals) {
            int start = interval[0], end = interval[1], real_index = interval[2];
            int index = search(intervals, n, end);
            ans[real_index] = (index < n ? intervals[index][2] : -1);
        }
        return ans;
    }
};
