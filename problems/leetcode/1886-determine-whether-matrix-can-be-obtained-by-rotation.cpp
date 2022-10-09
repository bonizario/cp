class Solution {
   private:
    void rotateMatrix(int n, vector<vector<int>>& mat) {
        // transpose matrix
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        // reverse each row
        for (int i = 0; i < n; i++) {
            int low = 0, high = n - 1;
            while (low < high) {
                swap(mat[i][low], mat[i][high]), high--, low++;
            }
        }
    }

    bool isEqual(int n, vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != target[i][j]) return false;
            }
        }
        return true;
    }

   public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat[0].size();
        for (int i = 0; i < 4; i++) {
            if (isEqual(n, mat, target)) return true;
            rotateMatrix(n, mat);
        }
        return false;
    }
};
