# Stack

Stacks are dynamic data structures that follow the Last In First Out (LIFO) principle.
The last item to be inserted into a stack is the first one to be deleted from it.

* Dynamic data structures
* Do not have a fixed size
* Do not consume a fixed amount of memory

Size of stack changes with each **push()** and **pop** operation.
Each operation increases and decreases the size of the stack by **1**, respectively.

# LeetCode

### 20. Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.

Example 1:

    Input: s = "()"
    Output: true

Example 2:

    Input: s = "()[]{}"
    Output: true

Example 3:

    Input: s = "(]"
    Output: false

Constraints:

    1 <= s.length <= 10^4
    s consists of parentheses only '()[]{}'.

```cpp
class Solution {
   public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stk.push(c);
            } else if (c == ')') {
                if (!stk.empty() && stk.top() == '(')
                    stk.pop();
                else
                    return false;
            } else if (c == ']') {
                if (!stk.empty() && stk.top() == '[')
                    stk.pop();
                else
                    return false;
            } else if (c == '}') {
                if (!stk.empty() && stk.top() == '{')
                    stk.pop();
                else
                    return false;
            }
        }
        if (!stk.empty()) return false;
        return true;
    }
};
```

### 155. Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

    MinStack() initializes the stack object.
    void push(int val) pushes the element val onto the stack.
    void pop() removes the element on the top of the stack.
    int top() gets the top element of the stack.
    int getMin() retrieves the minimum element in the stack.

You must implement a solution with **O(1)** time complexity for each function.

Example 1:

    Input
    ["MinStack","push","push","push","getMin","pop","top","getMin"]
    [[],[-2],[0],[-3],[],[],[],[]]

    Output
    [null,null,null,null,-3,null,0,-2]

    Explanation
    MinStack minStack = new MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin(); // return -3
    minStack.pop();
    minStack.top();    // return 0
    minStack.getMin(); // return -2

Constraints:

    -2^31 <= val <= 2^31 - 1
    Methods pop, top and getMin operations will always be called on non-empty stacks.
    At most 3 * 10^4 calls will be made to push, pop, top, and getMin.

```cpp
class MinStack {
   private:
    class Node {
       public:
        int val;
        int min_val;
        Node* next;

        Node(int val, int min_val, Node* next) {
            this->val = val;
            this->min_val = min_val;
            this->next = next;
        }
    };
    Node* head = nullptr;

   public:
    MinStack() {}

    void push(int val) {
        if (head == nullptr) {
            head = new Node(val, val, nullptr);
        } else {
            head = new Node(val, min(val, head->min_val), head);
        }
    }

    void pop() {
        head = head->next;
    }

    int top() {
        return head->val;
    }

    int getMin() {
        return head->min_val;
    }
};
```

### 150. Evaluate Reverse Polish Notation

You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

    The valid operators are '+', '-', '*', and '/'.
    Each operand may be an integer or another expression.
    The division between two integers always truncates toward zero.
    There will not be any division by zero.
    The input represents a valid arithmetic expression in a reverse polish notation.
    The answer and all the intermediate calculations can be represented in a 32-bit integer.

Example 1:

    Input: tokens = ["2","1","+","3","*"]
    Output: 9
    Explanation: ((2 + 1) * 3) = 9

Example 2:

    Input: tokens = ["4","13","5","/","+"]
    Output: 6
    Explanation: (4 + (13 / 5)) = 6

Example 3:

    Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
    Output: 22
    Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
    = ((10 * (6 / (12 * -11))) + 17) + 5
    = ((10 * (6 / -132)) + 17) + 5
    = ((10 * 0) + 17) + 5
    = (0 + 17) + 5
    = 17 + 5
    = 22

Constraints:

    1 <= tokens.length <= 10^4
    tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].

```cpp
class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (auto& token : tokens) {
            if (token != "+" && token != "-" && token != "*" && token != "/") {
                s.push(stoi(token));
                continue;
            }
            int second = s.top(); s.pop();
            int first = s.top(); s.pop();
            if (token == "+") {
                s.push(first + second);
            } else if (token == "-") {
                s.push(first - second);
            } else if (token == "*") {
                s.push(first * second);
            } else {
                s.push(first / second);
            }
        }
        return s.top();
    }
};
```

### 739. Daily Temperatures

Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

Example 1:

    Input: temperatures = [73,74,75,71,69,72,76,73]
    Output: [1,1,4,2,1,1,0,0]

Example 2:

    Input: temperatures = [30,40,50,60]
    Output: [1,1,1,0]

Example 3:

    Input: temperatures = [30,60,90]
    Output: [1,1,0]

Constraints:

    1 <= temperatures.length <= 10^5
    30 <= temperatures[i] <= 100

```cpp
class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int days, right_max = 0, n = temperatures.size();
        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            if (temperatures[i] >= right_max) {
                right_max = temperatures[i];
            } else {
                days = 1;
                while (temperatures[i] >= temperatures[i + days]) {
                    days += ans[i + days];
                }
                ans[i] = days;
            }
        }
        return ans;
    }
};

class Solution2 {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int t, n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                ans[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};
```

### 853. Car Fleet

There are n cars going to the same destination along a one-lane road. The destination is target miles away.

You are given two integer array position and speed, both of length n, where position[i] is the position of the ith car and speed[i] is the speed of the ith car (in miles per hour).

A car can never pass another car ahead of it, but it can catch up to it and drive bumper to bumper at the same speed. The faster car will slow down to match the slower car's speed. The distance between these two cars is ignored (i.e., they are assumed to have the same position).

A car fleet is some non-empty set of cars driving at the same position and same speed. Note that a single car is also a car fleet.

If a car catches up to a car fleet right at the destination point, it will still be considered as one car fleet.

Return the number of car fleets that will arrive at the destination.

Example 1:

    Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
    Output: 3
    Explanation:
    The cars starting at 10 (speed 2) and 8 (speed 4) become a fleet, meeting each other at 12.
    The car starting at 0 does not catch up to any other car, so it is a fleet by itself.
    The cars starting at 5 (speed 1) and 3 (speed 3) become a fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches target.
    Note that no other cars meet these fleets before the destination, so the answer is 3.

Example 2:

    Input: target = 10, position = [3], speed = [3]
    Output: 1
    Explanation: There is only one car, hence there is only one fleet.

Example 3:

    Input: target = 100, position = [0,2,4], speed = [4,2,1]
    Output: 1
    Explanation:
    The cars starting at 0 (speed 4) and 2 (speed 2) become a fleet, meeting each other at 4. The fleet moves at speed 2.
    Then, the fleet (speed 2) and the car starting at 4 (speed 1) become one fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches target.

Constraints:

    n == position.length == speed.length
    1 <= n <= 10^5
    0 < target <= 10^6
    0 <= position[i] < target
    All the values of position are unique.
    0 < speed[i] <= 10^6

```cpp
class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars(n);
        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], speed[i]};
        }
        sort(cars.begin(), cars.end());
        stack<double> fleets;
        for (int i = n - 1; i >= 0; i--) {
            double time = ((double)(target - cars[i].first)) / cars[i].second;
            if (fleets.empty() || fleets.top() < time) {
                // the current car arrives after fleets.top(), it becomes a new fleet
                fleets.push(time);
            }
        }
        return fleets.size();
    }
};
```

### 84. Largest Rectangle in Histogram

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:

    Input: heights = [2,1,5,6,2,3]
    Output: 10
    Explanation: The above is a histogram where width of each bar is 1.
    The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:

    Input: heights = [2,4]
    Output: 4

Constraints:

    1 <= heights.length <= 10^5
    0 <= heights[i] <= 10^4

```cpp
class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> ge_left(n);   // greater or equal from left
        vector<int> ge_right(n);  // greater or equal from right
        ge_left[0] = -1, ge_right[n - 1] = n;
        for (int i = 1; i < n; i++) {
            int p = i - 1;
            while (p >= 0 && heights[p] >= heights[i]) {
                p = ge_left[p];
            }
            ge_left[i] = p;
        }
        for (int i = n - 2; i >= 0; i--) {
            int p = i + 1;
            while (p < n && heights[p] >= heights[i]) {
                p = ge_right[p];
            }
            ge_right[i] = p;
        }
        int max_area = 0;
        for (int i = 0; i < n; i++) {
            max_area = max(max_area, heights[i] * (ge_right[i] - ge_left[i] - 1));
        }
        return max_area;
    }
};
```
