class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), max_length = 0;
        if (n == 0) {
            return max_length;
        }
        unordered_map<char, int> indexes;
        for (int left = 0, right = 0; right < n; right++) {
            if (indexes.find(s[right]) != indexes.end()) {
                left = max(left, indexes[s[right]] + 1);
            }
            indexes[s[right]] = right;
            max_length = max(max_length, right - left + 1);
        }
        return max_length;
    }
};
