class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int min_buy = INT_MAX, max_profit = 0, n = prices.size();
        for (auto& price : prices) {
            min_buy = min(min_buy, price);
            max_profit = max(max_profit, price - min_buy);
        }
        return max_profit;
    }
};

class Solution2 {
   public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0, n = prices.size();
        for (int left = 0, right = 1; right < n; right++) {
            int curr_profit = prices[right] - prices[left];
            if (curr_profit > 0) {
                max_profit = max(max_profit, curr_profit);
            } else {
                left = right;
            }
        }
        return max_profit;
    }
};
