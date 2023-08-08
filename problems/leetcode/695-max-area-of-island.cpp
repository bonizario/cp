class Solution {
   public:
    void dfs(vector<vector<int>>& grid, int n, int m, int i, int j, int* curr_area) {
        grid[i][j] = -1;
        *curr_area = *curr_area + 1;
        if (i > 0 && grid[i - 1][j] == 1) {
            dfs(grid, n, m, i - 1, j, curr_area);
        }
        if (i < n - 1 && grid[i + 1][j] == 1) {
            dfs(grid, n, m, i + 1, j, curr_area);
        }
        if (j > 0 && grid[i][j - 1] == 1) {
            dfs(grid, n, m, i, j - 1, curr_area);
        }
        if (j < m - 1 && grid[i][j + 1] == 1) {
            dfs(grid, n, m, i, j + 1, curr_area);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0, n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int curr_area = 0;
                    dfs(grid, n, m, i, j, &curr_area);
                    max_area = max(max_area, curr_area);
                }
            }
        }
        return max_area;
    }
};
