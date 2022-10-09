class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        i = ans = 0
        d = {}
        for j in range(n):
            if s[j] in d:
                i = max(d[s[j]], i)
            ans = max(ans, j - i + 1)
            d[s[j]] = j + 1
        return ans

"""
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        left = ans = 0
        found_chars = [0] * 128

        for right in range(n):
            r = s[right]
            found_chars[ord(r)] += 1
            while found_chars[ord(r)] > 1:
                l = s[left]
                found_chars[ord(l)] -= 1
                left += 1
            ans = max(ans, right - left + 1)
        return ans
"""
