class Solution {
   public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size(), left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (target < letters[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (target >= letters[left]) {
            left += 1;
        }
        return left < n ? letters[left] : letters[0];
    }
};
