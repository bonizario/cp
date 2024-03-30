class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_sum;
        int ans = 0, sum = 0;
        prefix_sum[0] = 1;  // always have 1 sum of zero, which is some of no elements
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int diff = sum - k;
            if (prefix_sum.count(diff) > 0) {
                ans += prefix_sum[diff];
            }
            prefix_sum[sum] += 1;  // construct prefix array
        }
        return ans;
    }
};
