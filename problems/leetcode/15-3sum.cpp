class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0, n = nums.size(); i < n; i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int target = nums[i], left = i + 1, right = n - 1;
            while (left < right) {
                if (nums[left] + nums[right] < -target) {
                    left += 1;
                } else if (nums[left] + nums[right] > -target) {
                    right -= 1;
                } else {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left += 1;
                    right -= 1;
                    while (left < right && nums[left] == nums[left - 1]) {
                        left += 1;
                    }
                }
            }
        }
        return ans;
    }
};
