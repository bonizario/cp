class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n - k + 1);
        deque<int> dq;
        for (int i = 0; i < n; i++) {
            if (!dq.empty() && dq.front() < i - k + 1) {
                // remove front() if it is out of the current window
                dq.pop_front();
            }
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                // ensure back() is greater or equal than nums[i]
                // deque will be monotonic decreasing
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1) {
                ans[i - k + 1] = nums[dq.front()];
            }
        }
        return ans;
    }
};
