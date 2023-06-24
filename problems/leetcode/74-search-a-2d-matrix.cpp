// Binary Search Matrix as an Array
class Solution {
    // Time Complexity: O(log(n*m))
    // Considering the matrix as an array
    // It could overflow if "n" and "m" were big enough
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int left = 0, right = n * m - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (target <= matrix[mid / m][mid % m]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return matrix[left / m][left % m] == target;
    }
};
