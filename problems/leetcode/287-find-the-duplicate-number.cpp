/*
 * Floyd's Tortoise and Hare Algorithm (Cycle Detection)
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * Steps:
 * 0. Map the array to a linked list;
 *    input: nums = [3,1,3,4,2]
 *    nodes: 0 -> 3 -> 4 -> 2 -> 3 && 1 <-> 1
 * 1. Fast travels 2x speed than slow;
 * 2. They will meet at some point in the cycle;
 * 3. The distance between the head to the beginning of the cycle is equal to
 *    the distance between the meeting point to the beginning of the cycle;
 * 4. Slow2 starts from the head and slow starts from the meeting point;
 * 5. They will meet at the beginning of the cycle.
 */
class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        for (int& num : nums) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        }
        int slow2 = 0;
        for (int& num : nums) {
            slow = nums[slow];
            slow2 = nums[slow2];
            if (slow == slow2) {
                break;
            }
        }
        return slow;
    }
};
