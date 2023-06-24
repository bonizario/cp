class Solution {
    // Time Complexity: O(n+m)
    // Considering the matrix as a binary search tree
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = m - 1;
        while (i < n && j >= 0) {
            if (target == matrix[i][j]) {
                return true;
            }
            if (target > matrix[i][j]) {
                i += 1;
            } else {
                j -= 1;
            }
        }
        return false;
    }
};
