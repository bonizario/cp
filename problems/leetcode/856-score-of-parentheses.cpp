class Solution {
   public:
    int scoreOfParentheses(string s) {
        stack<int> stk;
        int score = 0;
        for (auto c : s) {
            if (c == '(') {
                stk.push(score);
                score = 0;
            } else {
                score = stk.top() + max(score * 2, 1);
                stk.pop();
            }
        }
        return score;
    }
};

/*
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stk;
        int score;
        for (int i = 0, n = s.size(); i < n; i++) {
            if (s[i] == '(') {
                stk.push(-1);
            } else {
                if (stk.top() == -1) {
                    stk.pop();
                    stk.push(1);
                } else {
                    score = 0;
                    while (stk.top() != -1) {
                        score += stk.top();
                        stk.pop();
                    }
                    stk.pop();
                    stk.push(2 * score);
                }
            }
        }
        score = 0;
        while (!stk.empty()) {
            score += stk.top();
            stk.pop();
        }
        return score;
    }
};
*/
