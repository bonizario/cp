class Solution {
   public:
    vector<vector<int>> ans;

    void backtracking(int index, vector<int>& candidates, vector<int>& combination, int target) {
        // impossible combination
        if (target < 0) {
            return;
        }

        // possible combination
        if (target == 0) {
            ans.push_back(combination);
            return;
        }

        // out of bounds
        if (index == candidates.size()) {
            return;
        }

        // use the current element in the solution, and keep the same index because repetition is allowed
        combination.push_back(candidates[index]);
        backtracking(index, candidates, combination, target - candidates[index]);

        // do not use the current element in the solution
        combination.pop_back();
        backtracking(index + 1, candidates, combination, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> aux;

        backtracking(0, candidates, aux, target);

        return ans;
    }
};
