class Solution:
    def exist(self, board: list[list[str]], word: str) -> bool:
        delta_x = [1, 0, -1, 0]
        delta_y = [0, -1, 0, 1]
        height, width = len(board), len(board[0])
        ans = False

        def dfs(x, y, visited, pos=0):
            nonlocal ans
            if pos == len(word) - 1 or ans == True:
                ans = True
                return ans
            visited[y][x] = True
            for dx, dy in zip(delta_x, delta_y):
                xx, yy = x + dx, y + dy
                if xx < 0 or xx >= width or yy < 0 or yy >= height:
                    continue
                if not visited[yy][xx] and board[yy][xx] == word[pos + 1]:
                    dfs(xx, yy, visited, pos + 1)
                    visited[yy][xx] = False
            return ans

        for x in range(width):
            for y in range(height):
                if board[y][x] == word[0] and dfs(x, y, [[False] * width for _ in range(height)]):
                    return True

        return False

class Solution2:
    # simplification reduces the auxiliary space complexity
    # since we're not exploring diagonally, it's easier to just call dfs 4 times instead of delta x/y approach
    def exist(self, board: list[list[str]], word: str) -> bool:
        height, width = len(board), len(board[0])

        def dfs(x, y, pos=0):
            if pos == len(word):
                return True
            if x < 0 or x >= width or y < 0 or y >= height or board[y][x] != word[pos]:
                return False
            board[y][x] = "#"
            answer = (
                dfs(x + 1, y, pos + 1)
                or dfs(x, y + 1, pos + 1)
                or dfs(x - 1, y, pos + 1)
                or dfs(x, y - 1, pos + 1)
            )
            board[y][x] = word[pos]
            return answer

        for x in range(width):
            for y in range(height):
                if dfs(x, y):
                    return True

        return False
