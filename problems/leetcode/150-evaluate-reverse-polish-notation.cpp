class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (auto& token : tokens) {
            if (token != "+" && token != "-" && token != "*" && token != "/") {
                s.push(stoi(token));
                continue;
            }
            int second = s.top();
            s.pop();
            int first = s.top();
            s.pop();
            if (token == "+") {
                s.push(first + second);
            } else if (token == "-") {
                s.push(first - second);
            } else if (token == "*") {
                s.push(first * second);
            } else {
                s.push(first / second);
            }
        }
        return s.top();
    }
};
