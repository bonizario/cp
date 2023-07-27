class Solution {
   public:
    bool equal(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int s1_length = s1.size(), s2_length = s2.size(), curr_length = 0;
        vector<int> s1_frequency(26, 0), curr_frequency(26, 0);
        for (auto& c : s1) {
            s1_frequency[c - 'a'] += 1;
        }
        for (int start = 0, end = 0; end < s2_length; end++) {
            curr_frequency[s2[end] - 'a'] += 1;
            if (end - start + 1 > s1_length) {
                curr_frequency[s2[start] - 'a'] -= 1;
                start += 1;
            }
            if (end - start + 1 == s1_length && equal(curr_frequency, s1_frequency)) {
                return true;
            }
        }
        return false;
    }
};

class Solution2 {
   public:
    bool equal(unordered_map<char, int>& a, unordered_map<char, int>& b) {
        for (auto& [k, v] : a) {
            if (b[k] != v) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int s1_length = s1.size(), s2_length = s2.size(), curr_length = 0;
        unordered_map<char, int> s1_frequency, curr_frequency;
        for (auto c : s1) {
            s1_frequency[c] += 1;
        }
        for (int start = 0, end = 0; end < s2_length; end++) {
            curr_frequency[s2[end]] += 1;
            if (end - start + 1 > s1_length) {
                curr_frequency[s2[start]] -= 1;
                start += 1;
            }
            if (end - start + 1 == s1_length && equal(curr_frequency, s1_frequency)) {
                return true;
            }
        }
        return false;
    }
};
