class Solution {
   public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        int n = height.size(), ans = 0;
        vector<int> left_max(n), right_max(n);
        left_max[0] = height[0];
        for (int i = 1; i < n; i++) {
            left_max[i] = max(height[i], left_max[i - 1]);
        }
        right_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right_max[i] = max(height[i], right_max[i + 1]);
        }
        for (int i = 1; i < n - 1; i++) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }
};

class Solution2 {
   public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        int left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0, ans = 0;
        while (left < right) {
            left_max = max(left_max, height[left]);
            right_max = max(right_max, height[right]);
            if (left_max < right_max) {
                ans += (left_max - height[left++]);
            } else {
                ans += (right_max - height[right--]);
            }
        }
        return ans;
    }
};
