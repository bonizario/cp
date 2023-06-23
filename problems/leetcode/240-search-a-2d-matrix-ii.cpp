class Solution {
    // treat as binary search tree, root in the right upper corner:
    // n = rows, m = cols
    // if n == 1, skewed tree, O(m)
    // if n > 1, O(log(m))
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int row = 0, col = cols - 1;
        while (row < rows && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            }
            if (matrix[row][col] < target) {
                row += 1;
            } else {
                col -= 1;
            }
        }
        return false;
    }
};
