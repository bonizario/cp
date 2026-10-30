class Solution:
    # there is a binary choice to include or not the number nums[i] into a subset
    # so the total number of subsets is 2 * 2 * 2 * ... * 2 for N times where N = size of nums
    # the amount of recursive calls is 2 ^ N, worst subset length is N,
    # for each combination we need to copy into answer array so N * 2^N
    # time complexity: O(N*2^N)
    # space complexity: O(N*2^N) (we need to return all of them, cannot print one by one)
    def subsets(self, nums: list[int]) -> list[list[int]]:
        ans = []
        subset = []

        def dfs(i: int) -> None:
            if i >= len(nums):
                ans.append(subset.copy())
                return
            # decision to include nums[i]
            subset.append(nums[i])
            dfs(i + 1)
            # decision to NOT include nums[i]
            subset.pop() # backtracking, explore without including nums[i]
            dfs(i + 1)

        dfs(0)
        return ans

class Solution2:
    # simpler solution without backtracking and shared combination array
    def subsets(self, nums: list[int]) -> list[list[int]]:
        ans = []

        def dfs(i=0, subset=[]):
            if i == len(nums):
                ans.append(subset)
                return
            dfs(i + 1, subset + [nums[i]])
            dfs(i + 1, subset)

        dfs()
        return ans
