class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int days, right_max = 0, n = temperatures.size();
        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            if (temperatures[i] >= right_max) {
                right_max = temperatures[i];
            } else {
                days = 1;
                while (temperatures[i] >= temperatures[i + days]) {
                    days += ans[i + days];
                }
                ans[i] = days;
            }
        }
        return ans;
    }
};

class Solution2 {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int t, n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                ans[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};
