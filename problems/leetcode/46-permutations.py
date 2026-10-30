# we have N! permutations and each one of them have length N.
# in order to achieve each one of the N! permutations, we need to go through N calls.
# time complexity: O(N*N!)
# space complexity: O(N*N!)
class Solution:
    def permute(self, nums: list[int]) -> list[list[int]]:
        def backtrack(nums, permutation=[], ans=[]):
            if not nums:
                ans.append(permutation.copy())
            for i in range(len(nums)):
                new_nums = nums[:i] + nums[i+1:]  # remove nums[i] (not in-place, create copy)
                permutation.append(nums[i]) # add nums[i] to permutation
                backtrack(new_nums, permutation, ans)
                permutation.pop() # cleanup permutation (backtrack) so subsequent answers are created with a clean array
            return ans

        return backtrack(nums)

class Solution:
    # simpler solution without backtracking and shared permutation
    def permute(self, nums: list[int]) -> list[list[int]]:
        def recurse(current_nums, permutation=[], ans=[]):
            # len(permutation) == len(nums) also works (nums not current_nums!!)
            if not current_nums:
                ans.append(permutation)
            for i in range(len(current_nums)):
                recurse(current_nums[:i] + current_nums[i + 1:], permutation + [current_nums[i]])
            return ans

        return recurse(nums)
