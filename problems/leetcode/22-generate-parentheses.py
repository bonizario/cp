class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        def recurse(left=0, right=0, combination="", ans=[]):
            if len(combination) == 2 * n:
                ans.append(combination)
                return ans
            if left < n:
                recurse(left + 1, right, combination + "(", ans)
            if right < left:
                recurse(left, right + 1, combination + ")", ans)
            return ans

        return recurse()
