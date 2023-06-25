class Solution {
   public:
    int search(vector<int>& row, int m) {
        int left = 0, right = m - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (row[mid] < 0) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    int countNegatives(vector<vector<int>>& grid) {
        int count = 0, m = grid[0].size();
        for (auto& row : grid) {
            if (row[0] < 0) {
                count += m;
                continue;
            }
            if (row[m - 1] >= 0) {
                continue;
            }
            count += (m - search(row, m));
        }
        return count;
    }
};
