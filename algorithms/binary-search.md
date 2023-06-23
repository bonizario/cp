# Binary Search

Binary Search Template to minimize k, s.t. condition(k) is True

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
