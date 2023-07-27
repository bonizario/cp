class Solution {
   public:
    bool all_included(unordered_map<char, int>& freq, unordered_map<char, int>& window_freq) {
        for (auto& [k, v] : freq) {
            if (window_freq[k] < v) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s1, string s2) {
        unordered_map<char, int> s2_frequency, window_frequency;
        int s1_length = s1.size(), s2_length = s2.size();
        int min_length = INT_MAX, ans_start = -1, ans_end = -1;
        for (auto c : s2) {
            s2_frequency[c] += 1;
        }
        for (int start = 0, end = 0; end < s1_length; end++) {
            window_frequency[s1[end]] += 1;
            if (all_included(s2_frequency, window_frequency)) {
                do {
                    if (end - start + 1 < min_length) {
                        ans_start = start, ans_end = end, min_length = ans_end - ans_start + 1;
                    }
                    window_frequency[s1[start]] -= 1;
                    start += 1;
                } while (start < s1_length && window_frequency[s1[start - 1]] >= s2_frequency[s1[start - 1]]);
            }
        }
        return (ans_start == -1 ? "" : s1.substr(ans_start, ans_end - ans_start + 1));
    }
};
