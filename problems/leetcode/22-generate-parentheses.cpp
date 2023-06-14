class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        int current;
        deque<string> dq;
        string s;
        for (int i = 0; i < 2 * n; i++) {
            if (i == 0) {
                dq.push_back('(');
                current = dq.size();
                continue;
            }
            while (current--) {
                s = dq.front(), dq.pop_front();
                if (s.back() == '(') {
                    if (count(s.begin(), s.end(), '(') < n) {
                        dq.push_back(s + '(');
                    }
                    dq.push_back(s + ')');
                } else {
                    if (count(s.begin(), s.end(), '(') < n) {
                        dq.push_back(s + '(');
                    }
                    if (count(s.begin(), s.end(), '(') > count(s.begin(), s.end(), ')')) {
                        dq.push_back(s + ')');
                    }
                }
            }
            current = dq.size();
        }

        return vector<string>(dq.begin(), dq.end());
    }
};
