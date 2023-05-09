class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> letters;
        for (auto c : s) {
            letters[c] += 1;
        }
        for (auto c : t) {
            if (!letters.count(c)) {
                return false;
            }
            letters[c] -= 1;
        }
        for (auto &[k, v] : letters) {
            if (v != 0) {
                return false;
            }
        }
        return true;
    }
};
