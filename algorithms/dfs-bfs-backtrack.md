# Backtracking, DFS, and BFS

# LeetCode

### 22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:

    Input: n = 3
    Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:

    Input: n = 1
    Output: ["()"]

Constraints:

    1 <= n <= 8

```cpp
class Solution {
   public:
    void backtrack(vector<string>& parenthesis, string s, int open, int close, int n) {
        if (size(s) == 2 * n) {
            parenthesis.push_back(s);
            return;
        }
        if (open < n) {
            backtrack(parenthesis, s + "(", open + 1, close, n);
        }
        if (close < open) {
            backtrack(parenthesis, s + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> parenthesis;
        backtrack(parenthesis, "", 0, 0, n);
        return parenthesis;
    }
};
```

### 78. Subsets

Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

    Input: nums = [1,2,3]
    Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:

    Input: nums = [0]
    Output: [[],[0]]

Constraints:

    1 <= nums.length <= 10
    -10 <= nums[i] <= 10
    All the numbers of nums are unique.

```cpp
class Solution {
   private:
    // void print(vector<int>& arr) {
    //     if (!arr.size()) {
    //         cout << "[] "; return;
    //     }
    //     cout << "[";
    //     for (int i = 0; i < arr.size() - 1; i++) {
    //         cout << arr[i] << ",";
    //     }
    //     cout << arr[arr.size() - 1] << "] ";
    // }

    void backtrack(vector<int>& nums, int n, vector<vector<int>>& sets, vector<int>& current, int start) {
        sets.push_back(current);
        // cout << "CURRENT="; print(current); cout << "\n";
        // cout << "SUBSETS="; for (auto s : sets) print(s); cout << "\n";
        for (int i = start; i < n; i++) {
            current.push_back(nums[i]);
            backtrack(nums, n, sets, current, i + 1);
            current.pop_back();
        }
    }

   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sets;
        vector<int> current;
        backtrack(nums, nums.size(), sets, current, 0);
        return sets;
    }
};
```

### 39. Combination Sum

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the
frequency
of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Example 1:

    Input: candidates = [2,3,6,7], target = 7
    Output: [[2,2,3],[7]]
    Explanation:
    2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
    7 is a candidate, and 7 = 7.
    These are the only two combinations.

Example 2:

    Input: candidates = [2,3,5], target = 8
    Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:

    Input: candidates = [2], target = 1
    Output: []

Constraints:

    1 <= candidates.length <= 30
    2 <= candidates[i] <= 40
    All elements of candidates are distinct.
    1 <= target <= 40

```cpp
class Solution {
   public:
    vector<vector<int>> ans;

    void backtracking(int index, vector<int>& candidates, vector<int>& combination, int target) {
        // impossible combination
        if (target < 0) {
            return;
        }
        // possible combination
        if (target == 0) {
            ans.push_back(combination);
            return;
        }
        // out of bounds
        if (index == candidates.size()) {
            return;
        }
        // use the current element in the solution, and keep the same index because repetition is allowed
        combination.push_back(candidates[index]);
        backtracking(index, candidates, combination, target - candidates[index]);
        // do not use the current element in the solution
        combination.pop_back();
        backtracking(index + 1, candidates, combination, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> aux;
        backtracking(0, candidates, aux, target);
        return ans;
    }
};
```

### 79. Word Search

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example 1:

<img src="79-1.jpg" alt="" width="200" />

    Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
    Output: true

Example 2:

<img src="79-2.jpg" alt="" width="200" />

    Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
    Output: true

Example 3:

<img src="79-3.jpg" alt="" width="200" />

    Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
    Output: false

Constraints:

    m == board.length
    n = board[i].length
    1 <= m, n <= 6
    1 <= word.length <= 15
    board and word consists of only lowercase and uppercase English letters.

Follow up: Could you use search pruning to make your solution faster with a larger board?

```cpp
class Solution {
   public:
    bool dfs(vector<vector<char>>& board, int i, int j, int n, int m, string& word, int index) {
        if (index == word.size()) {
            return true;
        }
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[index]) {
            return false;
        }
        board[i][j] = '#';
        bool status = dfs(board, i, j - 1, n, m, word, index + 1) ||
                      dfs(board, i, j + 1, n, m, word, index + 1) ||
                      dfs(board, i - 1, j, n, m, word, index + 1) ||
                      dfs(board, i + 1, j, n, m, word, index + 1);
        board[i][j] = word[index];
        return status;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(board, i, j, n, m, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
```

### 200. Number of Islands

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

    Input: grid = [
    ["1","1","1","1","0"],
    ["1","1","0","1","0"],
    ["1","1","0","0","0"],
    ["0","0","0","0","0"]
    ]
    Output: 1

Example 2:

    Input: grid = [
    ["1","1","0","0","0"],
    ["1","1","0","0","0"],
    ["0","0","1","0","0"],
    ["0","0","0","1","1"]
    ]
    Output: 3

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 300
    grid[i][j] is '0' or '1'.

```cpp
class Solution {
   public:
    void dfs(vector<vector<char>>& grid, int i, int j, int n, int m) {
        grid[i][j] = '#';
        if (i > 0 && grid[i - 1][j] == '1') {
            dfs(grid, i - 1, j, n, m);
        }
        if (i < n - 1 && grid[i + 1][j] == '1') {
            dfs(grid, i + 1, j, n, m);
        }
        if (j > 0 && grid[i][j - 1] == '1') {
            dfs(grid, i, j - 1, n, m);
        }
        if (j < m - 1 && grid[i][j + 1] == '1') {
            dfs(grid, i, j + 1, n, m);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0, n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, n, m);
                    ans += 1;
                }
            }
        }
        return ans;
    }
};
```

### 695. Max Area of Island

You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

Example 1:

<img src="695-1.jpg" alt="" width="400" />

    Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
    Output: 6
    Explanation: The answer is not 11, because the island must be connected 4-directionally.

Example 2:

    Input: grid = [[0,0,0,0,0,0,0,0]]
    Output: 0

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 50
    grid[i][j] is either 0 or 1.

```cpp
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
```

### 417. Pacific Atlantic Water Flow

There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

Example 1:

<img src="417-1.jpg" alt="" width="200" />

    Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
    Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
    Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
    [0,4]: [0,4] -> Pacific Ocean
        [0,4] -> Atlantic Ocean
    [1,3]: [1,3] -> [0,3] -> Pacific Ocean
        [1,3] -> [1,4] -> Atlantic Ocean
    [1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean
        [1,4] -> Atlantic Ocean
    [2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean
        [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
    [3,0]: [3,0] -> Pacific Ocean
        [3,0] -> [4,0] -> Atlantic Ocean
    [3,1]: [3,1] -> [3,0] -> Pacific Ocean
        [3,1] -> [4,1] -> Atlantic Ocean
    [4,0]: [4,0] -> Pacific Ocean
        [4,0] -> Atlantic Ocean
    Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.

Example 2:

    Input: heights = [[1]]
    Output: [[0,0]]
    Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.

Constraints:

    m == heights.length
    n == heights[r].length
    1 <= m, n <= 200
    0 <= heights[r][c] <= 10^5

```cpp
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
```

### 130. Surrounded Regions

Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example 1:

<img src="130-1.jpg" alt="" width="200" />

    Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
    Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
    Explanation: Notice that an 'O' should not be flipped if:
    - It is on the border, or
    - It is adjacent to an 'O' that should not be flipped.
    The bottom 'O' is on the border, so it is not flipped.
    The other three 'O' form a surrounded region, so they are flipped.

Example 2:

    Input: board = [["X"]]
    Output: [["X"]]

Constraints:

    m == board.length
    n == board[i].length
    1 <= m, n <= 200
    board[i][j] is 'X' or 'O'.

```cpp
class Solution {
   public:
    void dfs(vector<vector<char>>& board, int n, int m, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != 'O') {
            return;
        }
        board[i][j] = '#';
        dfs(board, n, m, i - 1, j);
        dfs(board, n, m, i + 1, j);
        dfs(board, n, m, i, j - 1);
        dfs(board, n, m, i, j + 1);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            dfs(board, n, m, i, 0);
            dfs(board, n, m, i, m - 1);
        }
        for (int j = 0; j < m; j++) {
            dfs(board, n, m, 0, j);
            dfs(board, n, m, n - 1, j);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
```

### 994. Rotting Oranges

You are given an m x n grid where each cell can have one of three values:

* 0 representing an empty cell,
* 1 representing a fresh orange, or
* 2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Example 1:

<img src="994-1.png" alt="" width="600" />

    Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
    Output: 4

Example 2:

    Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
    Output: -1
    Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:

    Input: grid = [[0,2]]
    Output: 0
    Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 10
    grid[i][j] is 0, 1, or 2.

```cpp
class Solution {
    // TC: O(N * M) -> each cell is visited at least once
    // SC: O(N * M) -> worst case all oranges are rotten
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
        while (!rotten.empty() && fresh > 0) {
            minutes += 1;
            for (int i = 0, total = size(rotten); i < total; i++) {
                auto [x, y] = rotten.front();
                rotten.pop();
                for (auto& [dx, dy] : vector<pair<int, int>>{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}) {
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
```

# Beecrowd

### 1209. Festas de São Petersburgo

Nestas festas de São Petersburgo é sempre muito importante que cada um dos participantes tenha pelo menos um certo número de amigos na rede social. E, ao mesmo tempo, desejamos convidar o maior número possível de pessoas de São Petersburgo desde que a restrição com relação ao número de amigos seja satisfeita. Tal restrição diz que, para ser convidada a festa, a pessoa precisa ter pelo menos um número K de amigos na lista de convidados.

Sua tarefa neste problema é, dado o conjunto de pessoas da comunidade e a lista de suas relações, determinar quais devem ser chamadas para que a festa tenha a maior quantidade possível de participantes satisfazendo a restrição.

**Entrada**

A entrada é composta por diversas instâncias e termina com final de arquivo (EOF). A primeira linha de cada instância contém três inteiros N (1 ≤ N ≤ 1000), M e K (O ≤ K ≤ N) representando respectivamente o número de pessoas na comunidade, o número de relações de amizade nessa comunidade e o número mínimo de amigos convidados uma pessoa precisa ter para ser convidada. Cada pessoa da comunidade é identificada por números de 1 a N. Cada uma das próximas M linhas contém um par de pessoas indicando que elas são amigas na rede social.

**Saída**

Para cada instância imprima uma única linha contendo a lista das pessoas a serem convidadas separadas por um espaço em branco. A lista deve estar ordenada em ordem crescente. Caso ninguém possa ser convidado, imprima o número 0.

    Exemplo de Entrada

    6 6 2
    1 3
    3 5
    2 3
    2 4
    4 6
    6 2
    6 6 3
    1 2
    2 3
    3 1
    4 5
    5 6
    6 4

    Exemplo de Saída

    2 4 6
    0

```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000;

void dfs(vector<vector<int>>& adj, vector<int>& visited,
         int node, int k, vector<int>& friends) {
    if (visited[node] || friends[node] >= k) {
        return;
    }
    visited[node] = true;
    for (auto& u : adj[node]) {
        friends[u]--;
        if (friends[u] < k) {
            dfs(adj, visited, u, k, friends);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, m, k, a, b;
    vector<vector<int>> adj(MAX_N);
    vector<int> friends(MAX_N), visited(MAX_N), invited(MAX_N);

    while (cin >> n >> m >> k) {
        for (int i = 0; i < n; i++) {
            adj[i].clear(), friends[i] = 0, visited[i] = false;
        }
        while (m--) {
            cin >> a >> b;
            friends[--a] += 1, friends[--b] += 1;
            adj[a].push_back(b), adj[b].push_back(a);
        }
        for (int i = 0; i < n; i++) {
            dfs(adj, visited, i, k, friends);
        }
        int total_invited = 0;
        for (int i = 0; i < n; i++) {
            if (friends[i] >= k) {
                invited[total_invited++] = i + 1;
            }
        }
        if (total_invited == 0) {
            cout << "0\n";
            continue;
        }
        sort(invited.begin(), invited.begin() + total_invited);
        for (int i = 0; i < total_invited - 1; i++) {
            cout << invited[i] << " ";
        }
        cout << invited[total_invited - 1] << "\n";
    }

    return 0;
}
```

### 2545. Manyfile (Cicle Detection with DFS, Maximum Distance between root and leaf with BFS)

No ano de 2569, Vasya recebe de sua mãe um grandioso presente de aniversário, o código fonte do seu vídeo-game favorito, Aranha Paciente. Vasya corre direto ao seu computador, com 4096 núcleos de processamento, insere o disquete, digita ls no diretório do código e nota que ele é composto de N arquivos fonte e um Manyfile.

Um Manyfile é como uma receita de bolo para compilar o código. Ao se executar o comando many, o Manyfile é lido e os arquivos começam a ser compilados, de forma que o máximo de núcleos de processamento são utilizados simultaneamente. Se o mundo fosse perfeito, este processo seria muito rápido, uma vez que cada arquivo fonte do jogo demora exatamente um minuto para ser compilado, mas infelizmente a compilação de alguns arquivos depende da conclusão de outros, impossibilitando que todos os arquivos sejam processados simultaneamente.

Considerando a compilação da Aranha Paciente como terminada quando todos os seus N arquivos tiverem sido compilados e sabendo quais arquivos dependem de qual, escreva um programa que calcule para Vasya quantos minutos demorará para que a Aranha Paciente seja compilada.

**Entrada**

A entrada contém vários casos de teste. A primeira linha de cada caso contém o inteiro N (1 ≤ N ≤ 1000), o número de arquivos fonte da Aranha Paciente. Os arquivos são numerados de 1 a N. As N linhas seguintes descrevem os arquivos. A i-ésima linha contém um inteiro Mi (0 ≤ Mi < N) seguido de Mi inteiros com valor entre 1 e N e diferentes de i, representando o índice dos arquivos dos quais o arquivo i depende.

A entrada termina com fim-de-arquivo (EOF).

**Saída**

Para cada caso de teste, imprima uma única linha contendo o tempo total em minutos que demorará para que a Aranha Paciente seja compilada. Caso seja impossível terminal a compilação, imprima -1.

**Exemplo de Entrada**

    2
    1 2
    1 1
    3
    0
    1 3
    0

**Exemplo de Saída**

    -1
    2

```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000;

void dfs(vector<vector<int>>& adj, vector<int>& visited, int node, bool& has_cicle) {
    // already fully visited or cicle found
    if (visited[node] == 1 || has_cicle) {
        return;
    }
    // reached a node that was being visited in the same dfs, it's a cicle
    if (visited[node] == 0) {
        has_cicle = true;
        return;
    }
    visited[node] = 0;  // node is being visited
    for (auto& u : adj[node]) {
        dfs(adj, visited, u, has_cicle);
    }
    visited[node] = 1;  // node is fully visited
}

void bfs(vector<vector<int>>& adj, vector<int>& visited,
         int node, vector<int>& distance, int& max_minutes_spent) {
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    distance[node] = 1;  // the root node already spents 1 minute
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto& u : adj[v]) {
            if (!visited[u]) {
                q.push(u);
                visited[u] = true;
                distance[u] = distance[v] + 1;
                max_minutes_spent = max(max_minutes_spent, distance[u]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, m, u;
    vector<vector<int>> adj(MAX_N);
    vector<int> visited(MAX_N), is_root(MAX_N), distance(MAX_N);
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            adj[i].clear(), visited[i] = -1, is_root[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            cin >> m;
            for (int j = 0; j < m; j++) {
                cin >> u;
                u -= 1;
                is_root[u] = 0;
                adj[i].push_back(u);
            }
        }
        bool has_cicle = false;
        for (int i = 0; i < n; i++) {
            dfs(adj, visited, i, has_cicle);
        }
        if (has_cicle) {
            cout << "-1\n";
            continue;
        }
        int max_minutes_spent = 1;  // if every node is a root node without dependencies
        fill(visited.begin(), visited.begin() + n, 0);
        for (int i = 0; i < n; i++) {
            if (is_root[i]) {
                bfs(adj, visited, i, distance, max_minutes_spent);
            }
        }
        cout << max_minutes_spent << "\n";
    }

    return 0;
}
```