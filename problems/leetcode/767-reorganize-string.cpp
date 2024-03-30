class Solution {
   public:
    string reorganizeString(string s) {
        int most_frequent = 0;
        vector<int> count(26);

        // get occurrences count and most frequent character
        for (char c : s) {
            count[c - 'a'] += 1;
            if (count[c - 'a'] > count[most_frequent]) {
                most_frequent = c - 'a';
            }
        }

        // impossible to reorganize without repeating adjacent
        if (2 * count[most_frequent] - 1 > s.size()) {
            return "";
        }

        // intercalate most frequent character
        int i = 0;
        while (count[most_frequent]) {
            s[i] = ('a' + most_frequent);
            i += 2;
            count[most_frequent] -= 1;
        }

        // place remaining characters
        for (int j = 0; j < 26; j++) {
            while (count[j]) {
                if (i >= s.size()) {
                    i = 1;
                }
                s[i] = ('a' + j);
                count[j] -= 1;
                i += 2;
            }
        }

        return s;
    }
};
