class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> unique(nums.begin(), nums.end());
        return unique.size() != nums.size();
    }
};
