class Solution {
   private:
    int G[200], S[200], totalProvinces;

    int find(int a) {
        while (a != G[a]) {
            G[a] = G[G[a]];  // path compression
            a = G[a];
        }
        return a;
    }

    void unify(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (S[a] > S[b]) {
            G[b] = a;
            S[a] += S[b];
        } else {
            G[a] = b;
            S[b] += S[a];
        }
        totalProvinces--;
    }

   public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        for (int i = 0; i < n; i++) {
            G[i] = i, S[i] = 1;
        }
        totalProvinces = n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j]) unify(i, j);
            }
        }
        return totalProvinces;
    }
};
