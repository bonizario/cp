class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for (auto& n : s) {
            if (s.count(n - 1) == 0) {
                int i = n + 1, current = 1;
                while (true) {
                    if (s.count(i) == 0) {
                        break;
                    }
                    i++, current++;
                }
                if (current > longest) {
                    longest = current;
                }
            }
        }
        return longest;
    }
};
