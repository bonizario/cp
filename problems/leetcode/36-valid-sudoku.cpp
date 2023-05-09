class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> rows(9), columns(9);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (rows[i].count(board[i][j]) || columns[j].count(board[i][j])) {
                    return false;
                }
                rows[i].insert(board[i][j]);
                columns[j].insert(board[i][j]);
            }
        }
        for (int m = 0; m < 9; m += 3) {
            for (int n = 0; n < 9; n += 3) {
                set<char> sub_box;
                for (int i = m; i < m + 3; i++) {
                    for (int j = n; j < n + 3; j++) {
                        if (board[i][j] == '.') {
                            continue;
                        }
                        if (sub_box.count(board[i][j])) {
                            return false;
                        }
                        sub_box.insert(board[i][j]);
                    }
                }
            }
        }
        return true;
    }
};
