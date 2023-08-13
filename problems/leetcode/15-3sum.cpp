class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        if ((nums[n - 1] == 0 && nums[0] != 0) || (nums[n - 1] < 0)) {
            return ans;
        }
        for (int i = 0; i < n; i++) {
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
