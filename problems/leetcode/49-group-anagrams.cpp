class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (auto& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            m[key].push_back(s);
        }
        vector<vector<string>> groups;
        for (auto& [k, v] : m) {
            groups.push_back(v);
        }
        return groups;
    }
};

class Solution2 {
   private:
    struct vector_hasher {
        int operator()(const vector<int>& v) const {
            int hash = v.size();
            for (auto& i : v) {
                hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
            }
            return hash;
        }
    };

   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<vector<int>, vector<string>, vector_hasher> groups;
        for (auto& str : strs) {
            vector<int> count(26, 0);
            for (char c : str) {
                count[c - 'a'] += 1;
            }
            groups[count].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto& [group, strs_grouped] : groups) {
            ans.push_back(strs_grouped);
        }

        return ans;
    }
};
