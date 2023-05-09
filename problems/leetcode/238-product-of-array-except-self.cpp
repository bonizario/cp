class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix = 1, postfix = 1, total = nums.size();
        vector<int> ans(total, 1);
        for (int i = 0; i < total; i++) {
            ans[i] = prefix;
            prefix *= nums[i];
        }
        for (int i = total - 1; i >= 0; i--) {
            ans[i] *= postfix;
            postfix *= nums[i];
        }
        return ans;
    }
};
