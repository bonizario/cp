class Solution {
   public:
    int n, m;
    vector<vector<int>> result;
    vector<vector<bool>> pacific, atlantic;

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j) {
        if (visited[i][j]) {
            return;
        }
        visited[i][j] = true;
        if (pacific[i][j] && atlantic[i][j]) {
            result.push_back({i, j});
        }
        if (i < n - 1 && heights[i + 1][j] >= heights[i][j]) {
            dfs(heights, visited, i + 1, j);
        }
        if (i > 0 && heights[i - 1][j] >= heights[i][j]) {
            dfs(heights, visited, i - 1, j);
        }
        if (j < m - 1 && heights[i][j + 1] >= heights[i][j]) {
            dfs(heights, visited, i, j + 1);
        }
        if (j > 0 && heights[i][j - 1] >= heights[i][j]) {
            dfs(heights, visited, i, j - 1);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size(), m = heights[0].size();
        pacific = atlantic = vector<vector<bool>>(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            dfs(heights, pacific, i, 0), dfs(heights, atlantic, i, m - 1);
        }
        for (int j = 0; j < m; j++) {
            dfs(heights, pacific, 0, j), dfs(heights, atlantic, n - 1, j);
        }
        return result;
    }
};
