# time complexity: O(M*2^N), where M = length of longest combination, and N = length of candidates
# auxiliary space complexity: O(M)
class Solution:
    def combinationSum2(self, candidates: list[int], target: int) -> list[list[int]]:
        ans: list[list[int]] = []
        combination: list[int] = []
        candidates.sort()

        def dfs(i: int, current_sum: int) -> None:
            if current_sum == target:
                ans.append(combination.copy())
                return
            if current_sum > target or i >= len(candidates):
                return
            # include candidates[i]
            combination.append(candidates[i])
            dfs(i + 1, current_sum + candidates[i])
            # skip all occurrences of candidates[i]
            # we can ignore creating a new recursive tree using the same candidates[i] value
            # because all possible combinations using the all available candidates[i] value were explored
            # we can jump to the next unique value and avoid computing a bunch of useless recursive trees
            combination.pop()
            while i < len(candidates) - 1 and candidates[i] == candidates[i + 1]:
                i += 1
            dfs(i + 1, current_sum)

        dfs(0, 0)
        return ans

class Solution2:
    # simpler solution without backtracking and shared combination array
    def combinationSum2(self, candidates: list[int], target: int) -> list[list[int]]:
        ans = []
        candidates.sort()

        def recurse(i=0, current_sum=0, combination=[]):
            if current_sum == target:
                ans.append(combination)
                return
            if i == len(candidates) or current_sum > target:
                return
            recurse(i + 1, current_sum + candidates[i], combination + [candidates[i]])
            while i < len(candidates) - 1 and candidates[i] == candidates[i + 1]:
                i += 1
            recurse(i + 1, current_sum, combination)

        recurse()
        return ans
