class Solution:
    def subsetsWithDup(self, nums: list[int]) -> list[list[int]]:
        ans = []
        subset = []
        nums.sort()

        def dfs(i=0):
            if i == len(nums):
                ans.append(subset.copy())
                return
            subset.append(nums[i])
            dfs(i + 1)
            subset.pop()
            while i < len(nums) - 1 and nums[i] == nums[i+1]:
                i += 1
            dfs(i + 1)

        dfs()
        return ans

class Solution2:
    # simpler solution without backtracking and shared subset
    def subsetsWithDup(self, nums: list[int]) -> list[list[int]]:
        nums.sort()
        def recurse(i=0, subset=[], ans=[]):
            if i == len(nums):
                ans.append(subset)
                return ans
            recurse(i + 1, subset + [nums[i]], ans)
            while i < len(nums) - 1 and nums[i] == nums[i + 1]:
                i += 1
            recurse(i + 1, subset, ans)
            return ans

        return recurse()
