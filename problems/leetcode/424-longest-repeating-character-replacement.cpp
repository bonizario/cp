class Solution {
   public:
    int characterReplacement(string s, int k) {
        int n = s.size(), ans = 0, max_frequency = 0;
        unordered_map<char, int> frequency;
        for (int left = 0, right = 0; right < n; right++) {
            frequency[s[right]] += 1;
            max_frequency = max(max_frequency, frequency[s[right]]);
            // feasible: current_length <= max_frequency + k
            if (right - left + 1 > max_frequency + k) {
                frequency[s[left]] -= 1;
                left += 1;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
