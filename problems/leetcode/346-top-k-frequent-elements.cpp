class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (auto& num : nums) {
            count[num] += 1;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
        for (auto& [k, v] : count) {
            pq.push(make_pair(v, k));
        }
        vector<int> topKFrequents;
        while (k--) {
            pair<int, int> p = pq.top();
            pq.pop();
            topKFrequents.push_back(p.second);
        }
        return topKFrequents;
    }
};
