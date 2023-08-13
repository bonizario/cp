class Solution {
   public:
    void backtrack(vector<string>& parenthesis, string s, int open, int close, int n) {
        if (size(s) == 2 * n) {
            parenthesis.push_back(s);
            return;
        }
        if (open < n) {
            backtrack(parenthesis, s + "(", open + 1, close, n);
        }
        if (close < open) {
            backtrack(parenthesis, s + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> parenthesis;
        backtrack(parenthesis, "", 0, 0, n);
        return parenthesis;
    }
};
