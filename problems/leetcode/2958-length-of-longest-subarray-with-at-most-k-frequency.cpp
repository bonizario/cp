class Solution {
   public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> count = {{nums[0], 1}};
        int max_length = 1;
        for (int left = 0, right = 1; right < nums.size(); right++) {
            count[nums[right]] += 1;
            while (count[nums[right]] > k) {
                count[nums[left]] -= 1;
                left += 1;
            }
            max_length = max(max_length, right - left + 1);
        }
        return max_length;
    }
};
