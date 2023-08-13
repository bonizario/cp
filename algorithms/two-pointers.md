# Two Pointers

These kind of problems usually involve two pointers:

1. One slow-runner and the other fast-runner.

2. One pointer starts from the beginning while the other pointer starts from the end.

<br />

# LeetCode

### 238. Product of Array Except Self

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in **O(n)** time and **without using the division operation**.

Example 1:

    Input: nums = [1,2,3,4]
    Output: [24,12,8,6]

Example 2:

    Input: nums = [-1,1,0,-3,3]
    Output: [0,0,9,0,0]

Constraints:

    2 <= nums.length <= 10^5
    -30 <= nums[i] <= 30
    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

Follow up: Can you solve the problem in **O(1)** extra space complexity? (The output array does not count as extra space for space complexity analysis.)

```cpp
class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix = 1, postfix = 1, total = nums.size();
        vector<int> ans(total, 1);
        for (int i = 0; i < total; i++) {
            ans[i] = prefix;
            prefix *= nums[i];
        }
        for (int i = total - 1; i >= 0; i--) {
            ans[i] *= postfix;
            postfix *= nums[i];
        }
        return ans;
    }
};
```

### 11. Container With Most Water

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Example 1:

<img src="11-1.jpg" alt="" width="400" />

    Input: height = [1,8,6,2,5,4,8,3,7]
    Output: 49
    Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example 2:

    Input: height = [1,1]
    Output: 1

Constraints:

    n == height.length
    2 <= n <= 10^5
    0 <= height[i] <= 10^4

```cpp
class Solution {
   public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, ans = 0;
        while (left < right) {
            ans = max(ans, min(height[left], height[right]) * (right - left));
            if (height[left] <= height[right]) {
                left += 1;
            } else {
                right -= 1;
            }
        }
        return ans;
    }
};
```

### 42. Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:

<img src="42-1.png" alt="" width="400" />

    Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
    Output: 6
    Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:

    Input: height = [4,2,0,3,2,5]
    Output: 9

Constraints:

    n == height.length
    1 <= n <= 2 * 10^4
    0 <= height[i] <= 10^5

```cpp
class Solution {
   public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        int n = height.size(), ans = 0;
        vector<int> left_max(n), right_max(n);
        left_max[0] = height[0];
        for (int i = 1; i < n; i++) {
            left_max[i] = max(height[i], left_max[i - 1]);
        }
        right_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right_max[i] = max(height[i], right_max[i + 1]);
        }
        for (int i = 1; i < n - 1; i++) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }
};

class Solution {
   public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        int left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0, ans = 0;
        while (left < right) {
            left_max = max(left_max, height[left]);
            right_max = max(right_max, height[right]);
            if (left_max < right_max) {
                ans += (left_max - height[left++]);
            } else {
                ans += (right_max - height[right--]);
            }
        }
        return ans;
    }
};
```

### 15. 3Sum

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:

    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]
    Explanation:
    nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
    nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
    nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
    The distinct triplets are [-1,0,1] and [-1,-1,2].
    Notice that the order of the output and the order of the triplets does not matter.

Example 2:

    Input: nums = [0,1,1]
    Output: []
    Explanation: The only possible triplet does not sum up to 0.

Example 3:

    Input: nums = [0,0,0]
    Output: [[0,0,0]]
    Explanation: The only possible triplet sums up to 0.

Constraints:

    3 <= nums.length <= 3000
    -10^5 <= nums[i] <= 10^5

```cpp
class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        if ((nums[n - 1] == 0 && nums[0] != 0) || (nums[n - 1] < 0)) {
            return ans;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int target = nums[i], left = i + 1, right = n - 1;
            while (left < right) {
                if (nums[left] + nums[right] < -target) {
                    left += 1;
                } else if (nums[left] + nums[right] > -target) {
                    right -= 1;
                } else {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left += 1;
                    right -= 1;
                    while (left < right && nums[left] == nums[left - 1]) {
                        left += 1;
                    }
                }
            }
        }
        return ans;
    }
};
```

### 121. Best Time to Buy and Sell Stock

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:

    Input: prices = [7,1,5,3,6,4]
    Output: 5
    Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
    Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:

    Input: prices = [7,6,4,3,1]
    Output: 0
    Explanation: In this case, no transactions are done and the max profit = 0.

Constraints:

    1 <= prices.length <= 10^5
    0 <= prices[i] <= 10^4

```cpp
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int min_buy = INT_MAX, max_profit = 0;
        for (auto& price : prices) {
            min_buy = min(min_buy, price);
            max_profit = max(max_profit, price - min_buy);
        }
        return max_profit;
    }
};

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0, n = prices.size();
        for (int left = 0, right = 1; right < n; right++) {
            int curr_profit = prices[right] - prices[left];
            if (curr_profit > 0) {
                max_profit = max(max_profit, curr_profit);
            } else {
                left = right;
            }
        }
        return max_profit;
    }
};
```

### 3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without repeating characters.

Example 1:

    Input: s = "abcabcbb"
    Output: 3
    Explanation: The answer is "abc", with the length of 3.

Example 2:

    Input: s = "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.

Example 3:

    Input: s = "pwwkew"
    Output: 3
    Explanation: The answer is "wke", with the length of 3.
    Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Constraints:

    0 <= s.length <= 5 * 10^4
    s consists of English letters, digits, symbols and spaces.

```cpp
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), max_length = 0;
        if (n == 0) {
            return max_length;
        }
        unordered_map<char, int> indexes;
        for (int left = 0, right = 0; right < n; right++) {
            if (indexes.find(s[right]) != indexes.end()) {
                left = max(left, indexes[s[right]] + 1);
            }
            indexes[s[right]] = right;
            max_length = max(max_length, right - left + 1);
        }
        return max_length;
    }
};
```

### 424. Longest Repeating Character Replacement

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:

    Input: s = "ABAB", k = 2
    Output: 4
    Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:

    Input: s = "AABABBA", k = 1
    Output: 4
    Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
    The substring "BBBB" has the longest repeating letters, which is 4.
    There may exists other ways to achive this answer too.

Constraints:

    1 <= s.length <= 10^5
    s consists of only uppercase English letters.
    0 <= k <= s.length

```cpp
class Solution {
   public:
    int characterReplacement(string s, int k) {
        int n = s.size(), ans = 0, max_frequency = 0;
        unordered_map<char, int> frequency;
        for (int left = 0, right = 0; right < n; right++) {
            frequency[s[right]] += 1;
            max_frequency = max(max_frequency, frequency[s[right]]);
            // feasible: current_length <= max_frequency + k
            if (right - left + 1 > max_frequency + k) {
                frequency[s[left]] -= 1;
                left += 1;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
```

### 567. Permutation in String

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

Example 1:

    Input: s1 = "ab", s2 = "eidbaooo"
    Output: true
    Explanation: s2 contains one permutation of s1 ("ba").

Example 2:

    Input: s1 = "ab", s2 = "eidboaoo"
    Output: false

Constraints:

    1 <= s1.length, s2.length <= 10^4
    s1 and s2 consist of lowercase English letters.

```cpp
class Solution {
   public:
    bool equal(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int s1_length = s1.size(), s2_length = s2.size(), curr_length = 0;
        vector<int> s1_frequency(26, 0), curr_frequency(26, 0);
        for (auto& c : s1) {
            s1_frequency[c - 'a'] += 1;
        }
        for (int start = 0, end = 0; end < s2_length; end++) {
            curr_frequency[s2[end] - 'a'] += 1;
            if (end - start + 1 > s1_length) {
                curr_frequency[s2[start] - 'a'] -= 1;
                start += 1;
            }
            if (end - start + 1 == s1_length && equal(curr_frequency, s1_frequency)) {
                return true;
            }
        }
        return false;
    }
};

class Solution {
   public:
    bool equal(unordered_map<char, int>& a, unordered_map<char, int>& b) {
        for (auto& [k, v] : a) {
            if (b[k] != v) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int s1_length = s1.size(), s2_length = s2.size(), curr_length = 0;
        unordered_map<char, int> s1_frequency, curr_frequency;
        for (auto c : s1) {
            s1_frequency[c] += 1;
        }
        for (int start = 0, end = 0; end < s2_length; end++) {
            curr_frequency[s2[end]] += 1;
            if (end - start + 1 > s1_length) {
                curr_frequency[s2[start]] -= 1;
                start += 1;
            }
            if (end - start + 1 == s1_length && equal(curr_frequency, s1_frequency)) {
                return true;
            }
        }
        return false;
    }
};
```

### 76. Minimum Window Substring

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

Example 1:

    Input: s = "ADOBECODEBANC", t = "ABC"
    Output: "BANC"
    Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:

    Input: s = "a", t = "a"
    Output: "a"
    Explanation: The entire string s is the minimum window.

Example 3:

    Input: s = "a", t = "aa"
    Output: ""
    Explanation: Both 'a's from t must be included in the window.
    Since the largest window of s only has one 'a', return empty string.

Constraints:

    m == s.length
    n == t.length
    1 <= m, n <= 10^5
    s and t consist of uppercase and lowercase English letters.

Follow up: Could you find an algorithm that runs in O(m + n) time?

```cpp
class Solution {
   public:
    bool all_included(unordered_map<char, int>& freq, unordered_map<char, int>& window_freq) {
        for (auto& [k, v] : freq) {
            if (window_freq[k] < v) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s1, string s2) {
        unordered_map<char, int> s2_frequency, window_frequency;
        int s1_length = s1.size(), s2_length = s2.size();
        int min_length = INT_MAX, ans_start = -1, ans_end = -1;
        for (auto c : s2) {
            s2_frequency[c] += 1;
        }
        for (int start = 0, end = 0; end < s1_length; end++) {
            window_frequency[s1[end]] += 1;
            if (all_included(s2_frequency, window_frequency)) {
                do {
                    if (end - start + 1 < min_length) {
                        ans_start = start, ans_end = end, min_length = ans_end - ans_start + 1;
                    }
                    window_frequency[s1[start]] -= 1;
                    start += 1;
                } while (start < s1_length && window_frequency[s1[start - 1]] >= s2_frequency[s1[start - 1]]);
            }
        }
        return (ans_start == -1 ? "" : s1.substr(ans_start, ans_end - ans_start + 1));
    }
};
```

### 239. Sliding Window Maximum

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

Example 1:

    Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
    Output: [3,3,5,5,6,7]
    Explanation:
    Window position                Max
    ---------------               -----
    [1  3  -1] -3  5  3  6  7       3
    1 [3  -1  -3] 5  3  6  7       3
    1  3 [-1  -3  5] 3  6  7       5
    1  3  -1 [-3  5  3] 6  7       5
    1  3  -1  -3 [5  3  6] 7       6
    1  3  -1  -3  5 [3  6  7]      7

Example 2:

    Input: nums = [1], k = 1
    Output: [1]

Constraints:

    1 <= nums.length <= 10^5
    -10^4 <= nums[i] <= 10^4
    1 <= k <= nums.length

```cpp
class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n - k + 1);
        deque<int> dq;
        for (int i = 0; i < n; i++) {
            if (!dq.empty() && dq.front() < i - k + 1) {
                // remove front() if it is out of the current window
                dq.pop_front();
            }
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                // ensure back() is greater or equal than nums[i]
                // deque will be monotonic decreasing
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1) {
                ans[i - k + 1] = nums[dq.front()];
            }
        }
        return ans;
    }
};
```
