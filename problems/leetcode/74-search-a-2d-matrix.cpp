class Solution {
    // treat as array aproach:
    // n = rows, m = cols
    // O(log(n*m)), might overflow if n*m is too big
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        if (rows == 0 || cols == 0) {
            return false;
        }
        int l = 0, r = rows * cols - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int i = m / cols, j = m % cols;
            if (matrix[i][j] == target) {
                return true;
            }
            if (matrix[i][j] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return false;
    }
};

class Solution2 {
    // treat as binary search tree, root in the right upper corner:
    // n = rows, m = cols
    // if n == 1, skewed tree, O(m)
    // if n > 1, O(n + m), slower than previous solution
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
