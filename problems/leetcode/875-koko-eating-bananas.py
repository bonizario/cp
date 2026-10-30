# time complexity: O(N*log(K)), where N = piles.length, and K = max(piles)
class Solution:
    def minEatingSpeed(self, piles: list[int], h: int) -> int:
        def can_eat(k: int):
            if k == 0: return False
            return sum((pile - 1) // k + 1 for pile in piles) <= h

        left, right = 0, max(piles)
        while left < right:
            mid = left + (right - left) // 2
            if can_eat(mid):
                right = mid
            else:
                left = mid + 1

        return left
