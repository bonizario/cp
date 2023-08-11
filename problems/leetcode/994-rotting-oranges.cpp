class Solution {
    // TC: O(NM) -> each cell is visited at least once
    // SC: O(NM) -> worst case all oranges are rotten
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = size(grid);
        if (n == 0) {
            return -1;
        }

        int m = size(grid[0]), fresh = 0, minutes = 0;
        queue<pair<int, int>> rotten;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    rotten.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh += 1;
                }
            }
        }

        vector<pair<int, int>> dxy = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!rotten.empty() && fresh > 0) {
            minutes += 1;
            for (int i = 0, total = size(rotten); i < total; i++) {
                auto [x, y] = rotten.front();
                rotten.pop();
                for (auto [dx, dy] : dxy) {
                    int xx = x + dx, yy = y + dy;
                    if (xx < 0 || xx == n || yy < 0 || yy == m || grid[xx][yy] != 1) {
                        continue;
                    }
                    fresh -= 1;
                    grid[xx][yy] = 2;
                    rotten.push({xx, yy});
                }
            }
        }
        return (fresh == 0 ? minutes : -1);
    }
};
