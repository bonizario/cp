# solved by myself with backtracking, couldn't reason about the complexity
# got complexity explanation from https://leetcode.com/problems/combination-sum/solutions/1755084/detailed-time-and-space-complexity-analy-jh8x
# if we could not reuse elements, the time complexity would be 2^N where N is size of candidates,
# because we would only have 2 choices per element.
# we can, so the time complexity for a single element is 2^Ti where Ti = target/candidates[i]
# so time complexity is 2^K where K = T1+T2+T3+...+TN, or more generally K = target/min_candidate
# we also need to consider the time complexity of copying the combination into answer array
# time complexity: O(M*2^K), where M = length of longest combination, and K = T1+T2+...+TN
# auxiliary space complexity: O(M)
class Solution:
    def combinationSum(self, candidates: list[int], target: int) -> list[list[int]]:
        # for each number, I can choose either to add it or not
        # when the current sum is equal to target, we have a valid answer
        # when it's bigger, give up on the recursion, don't keep adding
        
        # WRONG THOUGHT PROCESS:
        # each recursive call I have 3 options:
        # - do not use candidates[i] (increment i)
        # - use candidates[i] and attempt to use it again (maintain i)
        # - use candidates[i] and do not attempt to use it again (increment i)

        # CORRECT:
        # I don't need the third option, just the first 2 will generate all posibilites.
        # dfs(i + 1, current_sum + candidates[i]) duplicate the answers.
        # by trying to reuse the same number until current_sum >= target, the next dfs
        # call with combination.pop() will take care of going through possibilities that are
        # not using that specific combination of numbers
        ans: list[list[int]] = []
        combination: list[int] = []

        def dfs(i: int, current_sum: int) -> None:
            # print(f'i={i} current_sum={current_sum} combination={combination}')
            if current_sum > target or i >= len(candidates):
                return
            elif current_sum == target:
                ans.append(combination.copy())
                return
            # use candidates[i] and attempt to use it again
            combination.append(candidates[i])
            dfs(i, current_sum + candidates[i])

            # WRONG: use candidates[i] and do not attempt to use it again
            # WRONG: dfs(i + 1, current_sum + candidates[i])

            # do not use candidates[i]
            combination.pop()
            dfs(i + 1, current_sum)
        
        dfs(0, 0)
        return ans

class Solution2:
    # simpler solution without backtracking and shared combination array
    def combinationSum(self, candidates: list[int], target: int) -> list[list[int]]:
        ans = []

        def recurse(i=0, current_sum=0, combination=[]):
            if current_sum == target:
                ans.append(combination)
                return
            if i == len(candidates) or current_sum > target:
                return
            # simply attempt to use candidates[i] or not
            recurse(i, current_sum + candidates[i], combination + [candidates[i]])
            recurse(i + 1, current_sum, combination)

        recurse()
        return ans
