class Solution {
   private:
    // void print(vector<int>& arr) {
    //     if (!arr.size()) {
    //         cout << "[] ";
    //         return;
    //     }
    //     cout << "[";
    //     for (int i = 0; i < arr.size() - 1; i++) {
    //         cout << arr[i] << ",";
    //     }
    //     cout << arr[arr.size() - 1] << "] ";
    // }

    void backtrack(vector<int>& nums, int n, vector<vector<int>>& sets, vector<int>& current, int start) {
        sets.push_back(current);

        // cout << "CURRENT="; print(current); cout << "\n";
        // cout << "SUBSETS="; for (auto s : sets) print(s); cout << "\n";

        for (int i = start; i < n; i++) {
            current.push_back(nums[i]);
            backtrack(nums, n, sets, current, i + 1);
            current.pop_back();
        }
    }

   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sets;
        vector<int> current;
        backtrack(nums, nums.size(), sets, current, 0);
        return sets;
    }
};
