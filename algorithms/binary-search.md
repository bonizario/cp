# Binary Search

Binary Search Template to minimize k, condition(k) is True.

1. Correctly initialize the boundary variables "left" and "right".
Only one rule: set up the boundary to include all possible elements;

2. Decide return value. Is it "return left" or "return left - 1"?
After exiting the while loop, "left" is the minimal k satisfying the "condition" function;

3. Design the "condition" function.

### C++ Template
```cpp
bool condition(int value) {
}

int binary_search(vector<int>& elements) {
    int left = 0, right = elements.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (condition(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
```

### Python Template
```py
def binary_search(array) -> int:
    def condition(value) -> bool:
        pass

    left, right = 0, len(array)
    while left < right:
        mid = left + (right - left) // 2
        if condition(mid):
            right = mid
        else:
            left = mid + 1
    return left
```

<br />

# LeetCode

### 875. Koko Eating Bananas

Koko loves to eat bananas. There are **n** piles of bananas, the **ith** pile has **piles[i]** bananas. The guards have gone and will come back in **h** hours.

Koko can decide her bananas-per-hour eating speed of **k**. Each hour, she chooses some pile of bananas and eats **k** bananas from that pile. If the pile has less than **k** bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer **k** such that she can eat all the bananas within **h** hours.

Example 1:

    Input: piles = [3,6,7,11], h = 8
    Output: 4

Example 2:

    Input: piles = [30,11,23,4,20], h = 5
    Output: 30

Example 3:

    Input: piles = [30,11,23,4,20], h = 6
    Output: 23

Constraints:

    1 <= piles.length <= 10^4
    piles.length <= h <= 10^9
    1 <= piles[i] <= 10^9

```cpp
class Solution {
   public:
    bool feasible(const vector<int>& piles, int speed, int available_hours) {
        int required_hours = accumulate(piles.begin(), piles.end(), 0, [&](int hours, int pile) {
            return hours + ((pile - 1) / speed + 1);
        });
        return required_hours <= available_hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (feasible(piles, mid, h)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
```

### 35. Search Insert Position

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with **O(log n)** runtime complexity.

Example 1:

    Input: nums = [1,3,5,6], target = 5
    Output: 2

Example 2:

    Input: nums = [1,3,5,6], target = 2
    Output: 1

Example 3:

    Input: nums = [1,3,5,6], target = 7
    Output: 4

Constraints:

    1 <= nums.length <= 10^4
    -10^4 <= nums[i] <= 10^4
    nums contains distinct values sorted in ascending order.
    -10^4 <= target <= 10^4

```cpp
class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (target <= nums[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
```

### 74. Search a 2D Matrix

You are given an **m x n** integer matrix **matrix** with the following two properties:

1. Each row is sorted in non-decreasing order.
2. The first integer of each row is greater than the last integer of the previous row.

Given an integer **target**, return **true** if **target** is in **matrix** or **false** otherwise.

You must write a solution in **O(log(m * n))** time complexity.

Example 1:

<img src="74-1.jpg" alt="" width="200" />

    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
    Output: true

Example 2:

<img src="74-2.jpg" alt="" width="200" />

    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
    Output: false

Constraints:

    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 100
    -10^4 <= matrix[i][j], target <= 10^4

```cpp
// Binary Search Matrix as an Array
class Solution {
    // Time Complexity: O(log(N * M))
    // Considering the matrix as an array
    // It could overflow if "N" and "M" were big enough
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int left = 0, right = n * m - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (target <= matrix[mid / m][mid % m]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return matrix[left / m][left % m] == target;
    }
};
```

### 240. Search a 2D Matrix II

Write an efficient algorithm that searches for a value **target** in an **m x n** integer matrix **matrix**. This matrix has the following properties:

1. Integers in each row are sorted in ascending from left to right.
2. Integers in each column are sorted in ascending from top to bottom.

Example 1:

<img src="240-1.jpg" alt="" width="200" />

    Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
    Output: true

Example 2:

<img src="240-2.jpg" alt="" width="200" />

    Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
    Output: false

Constraints:

    m == matrix.length
    n == matrix[i].length
    1 <= n, m <= 300
    -10^9 <= matrix[i][j] <= 10^9
    All the integers in each row are sorted in ascending order.
    All the integers in each column are sorted in ascending order.
    -10^9 <= target <= 10^9

```cpp
class Solution {
    // Time Complexity: O(N + M)
    // Considering the matrix as a binary search tree
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = m - 1;
        while (i < n && j >= 0) {
            if (target == matrix[i][j]) {
                return true;
            }
            if (target > matrix[i][j]) {
                i += 1;
            } else {
                j -= 1;
            }
        }
        return false;
    }
};
```

### 33. Search in Rotated Sorted Array

There is an integer array **nums** sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is **possibly rotated** at an unknown pivot index **k** (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array **nums** after the possible rotation and an integer **target**, return the index of **target** if it is in nums, or -1 if it is not in nums.

You must write an algorithm with **O(log n)** runtime complexity.

Example 1:

    Input: nums = [4,5,6,7,0,1,2], target = 0
    Output: 4

Example 2:

    Input: nums = [4,5,6,7,0,1,2], target = 3
    Output: -1

Example 3:

    Input: nums = [1], target = 0
    Output: -1

Constraints:

    1 <= nums.length <= 5000
    -10^4 <= nums[i] <= 10^4
    All values of nums are unique.
    nums is an ascending array that is possibly rotated.
    -10^4 <= target <= 10^4

```cpp
// Binary Search Twice
class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        int begin_index = left; // minimum in the rotated sorted array
        if (target > nums[n - 1]) {
            left = 0, right = begin_index - 1;
        } else {
            right = n - 1;
        }
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (target <= nums[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return target == nums[left] ? left : -1;
    }
};
```

### 154. Find Minimum in Rotated Sorted Array II

Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:

* [4,5,6,7,0,1,4] if it was rotated 4 times.
* [0,1,4,4,5,6,7] if it was rotated 7 times.

Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.

You must decrease the overall operation steps as much as possible.

Example 1:

    Input: nums = [1,3,5]
    Output: 1

Example 2:

    Input: nums = [2,2,2,0,1]
    Output: 0

Constraints:

    n == nums.length
    1 <= n <= 5000
    -5000 <= nums[i] <= 5000
    nums is sorted and rotated between 1 and n times.

Follow up: This problem is similar to **Find Minimum in Rotated Sorted Array**, but nums may contain duplicates. Would this affect the runtime complexity? How and why? (Worst case becomes O(n))

```cpp
class Solution {
   public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        if (nums[right] > nums[left]) {
            return nums[left];
        }
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[right]) {
                right = mid;
            } else if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                if (nums[right - 1] > nums[right]) {  // right > 0 always
                    left = right;
                    break;
                }
                right -= 1;
            }
        }
        return nums[left];
    }
};
```

### 436. Find Right Interval

You are given an array of intervals, where intervals[i] = [starti, endi] and each starti is unique.

The right interval for an interval i is an interval j such that startj >= endi and startj is minimized. Note that i may equal j.

Return an array of right interval indices for each interval i. If no right interval exists for interval i, then put -1 at index i.

Example 1:

    Input: intervals = [[1,2]]
    Output: [-1]
    Explanation: There is only one interval in the collection, so it outputs -1.

Example 2:

    Input: intervals = [[3,4],[2,3],[1,2]]
    Output: [-1,0,1]
    Explanation: There is no right interval for [3,4].
    The right interval for [2,3] is [3,4] since start0 = 3 is the smallest start that is >= end1 = 3.
    The right interval for [1,2] is [2,3] since start1 = 2 is the smallest start that is >= end2 = 2.

Example 3:

    Input: intervals = [[1,4],[2,3],[3,4]]
    Output: [-1,2,-1]
    Explanation: There is no right interval for [1,4] and [3,4].
    The right interval for [2,3] is [3,4] since start2 = 3 is the smallest start that is >= end1 = 3.

Constraints:

    1 <= intervals.length <= 2 * 10^4
    intervals[i].length == 2
    -10^6 <= starti <= endi <= 10^6
    The start point of each interval is unique.

```cpp
class Solution {
   public:
    int search(vector<vector<int>>& intervals, int n, int target) {
        int left = 0, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (target <= intervals[mid][0]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });
        vector<int> ans(n);
        for (auto& interval : intervals) {
            int start = interval[0], end = interval[1], real_index = interval[2];
            int index = search(intervals, n, end);
            ans[real_index] = (index < n ? intervals[index][2] : -1);
        }
        return ans;
    }
};
```

### 34. Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with **O(log n)** runtime complexity.

Example 1:

    Input: nums = [5,7,7,8,8,10], target = 8
    Output: [3,4]

Example 2:

    Input: nums = [5,7,7,8,8,10], target = 6
    Output: [-1,-1]

Example 3:

    Input: nums = [], target = 0
    Output: [-1,-1]

Constraints:

    0 <= nums.length <= 10^5
    -10^9 <= nums[i] <= 10^9
    nums is a non-decreasing array.
    -10^9 <= target <= 10^9

```cpp
// Binary Search Twice
class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return {-1, -1};
        }
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (target <= nums[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (target != nums[left]) {
            return {-1, -1};
        }
        int first = left;
        left = 0, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (target < nums[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        int last = left - 1;
        return {first, last};
    }
};
```

### 1539. Kth Missing Positive Number

Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.

Example 1:

    Input: arr = [2,3,4,7,11], k = 5
    Output: 9
    Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

Example 2:

    Input: arr = [1,2,3,4], k = 2
    Output: 6
    Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.

Constraints:

    1 <= arr.length <= 1000
    1 <= arr[i] <= 1000
    1 <= k <= 1000
    arr[i] < arr[j] for 1 <= i < j <= arr.length

```cpp
class Solution {
   public:
    int missing(vector<int>& arr, int index) {
        return arr[index] - index - 1;
    }

    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (missing(arr, mid) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        // if (left == 0) {
        //     return arr[left] > k ? k : arr[left] + k - missing(arr, left);
        // }
        // return arr[left - 1] + k - missing(arr, left - 1);

        // simplification:
        // arr[left-1] + k - arr[left-1] + (left - 1) + 1
        // equals to:
        // left + k
        return left + k;
    }
};
```

### 275. H-Index II

Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper and citations is sorted in ascending order, return the researcher's h-index.

According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.

You must write an algorithm that runs in logarithmic time.

Example 1:

    Input: citations = [0,1,3,5,6]
    Output: 3
    Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had received 0, 1, 3, 5, 6 citations respectively.
    Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.

Example 2:

    Input: citations = [1,2,100]
    Output: 2

Constraints:

    n == citations.length
    1 <= n <= 10^5
    0 <= citations[i] <= 1000
    citations is sorted in ascending order.

```cpp
class Solution {
   public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (citations[mid] >= n - mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return min(n - left, citations[left]);
    }
};
```

### 540. Single Element in a Sorted Array

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in **O(log n)** time and **O(1)** space.

Example 1:

    Input: nums = [1,1,2,3,3,4,4,8,8]
    Output: 2

Example 2:

    Input: nums = [3,3,7,7,10,11,11]
    Output: 10

Constraints:

    1 <= nums.length <= 10^5
    0 <= nums[i] <= 10^5

```cpp
class Solution {
   public:
    int isEven(int n) {
        return (n & 1) == 0;
    }

    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if ((mid > 0 && nums[mid] == nums[mid - 1] && isEven(n - mid - 1)) ||
                (mid < n - 1 && nums[mid] == nums[mid + 1] && isEven(n - mid))) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (left == 0 || left == n - 1) {
            return nums[left];
        }
        return nums[left - 1];
    }
};
```

### 852. Peak Index in a Mountain Array

An array arr is a mountain if the following properties hold:

* arr.length >= 3
* There exists some i with 0 < i < arr.length - 1 such that:
    * arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
    * arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

You must solve it in **O(log(arr.length))** time complexity.

Example 1:

    Input: arr = [0,1,0]
    Output: 1

Example 2:

    Input: arr = [0,2,1,0]
    Output: 1

Example 3:

    Input: arr = [0,10,5,2]
    Output: 1

Constraints:

    3 <= arr.length <= 10^5
    0 <= arr[i] <= 10^6
    arr is guaranteed to be a mountain array.

```cpp
class Solution {
   public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] <= arr[mid - 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left - 1;
    }
};
```

### 658. Find K Closest Elements

Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

* |a - x| < |b - x|, or
* |a - x| == |b - x| and a < b

Example 1:

    Input: arr = [1,2,3,4,5], k = 4, x = 3
    Output: [1,2,3,4]

Example 2:

    Input: arr = [1,2,3,4,5], k = 4, x = -1
    Output: [1,2,3,4]

Constraints:

    1 <= k <= arr.length
    1 <= arr.length <= 10^4
    arr is sorted in ascending order.
    -10^4 <= arr[i], x <= 10^4

```cpp
class Solution {
    // Time Complexity: O(log(N - K)) to binary research and find result
    // Space Complexity: O(K) to create the returned list.
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - k;
        while (left < right) {
            int mid = left + (right - left) / 2;
            // sliding window arr[mid] ~ arr[mid + k]

            // case 1: x - A[mid] < A[mid + k] - x, need to slide the window to the left
            // ----x----A[mid]----------------------A[mid + k]---------

            // case 2: x - A[mid] < A[mid + k] - x, need to slide the window to the left
            // ---------A[mid]----x-----------------A[mid + k]---------

            // case 3: x - A[mid] > A[mid + k] - x, need to slide the window to the right
            // ---------A[mid]-----------------x----A[mid + k]---------

            // case 4: x - A[mid] > A[mid + k] - x, need to slide the window to the right
            // ---------A[mid]----------------------A[mid + k]----x----

            if (x - arr[mid] <= arr[mid + k] - x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};
```

Note that, you SHOULD NOT compare the absolute value of abs(x - A[mid]) and abs(A[mid + k] - x).
It fails at cases like A = [1,1,2,2,2,2,2,3,3], x = 3, k = 3
