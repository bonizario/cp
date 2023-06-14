class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int first, second;
        for (auto& token : tokens) {
            if (token == "+") {
                second = s.top();
                s.pop();
                first = s.top();
                s.pop();
                s.push(first + second);
            } else if (token == "-") {
                second = s.top();
                s.pop();
                first = s.top();
                s.pop();
                s.push(first - second);
            } else if (token == "*") {
                second = s.top();
                s.pop();
                first = s.top();
                s.pop();
                s.push(first * second);
            } else if (token == "/") {
                second = s.top();
                s.pop();
                first = s.top();
                s.pop();
                s.push(first / second);
            } else {
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};
