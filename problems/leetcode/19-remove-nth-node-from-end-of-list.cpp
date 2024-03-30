/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || !head->next) {
            return nullptr;
        }

        // compute size of linked list
        int size = 0;
        ListNode* ptr = head;
        while (ptr) {
            ptr = ptr->next;
            size += 1;
        }

        // edge case (head is removed)
        if (size - n == 0) {
            return head->next;
        }

        // remove nth node from the end of list
        int index = 0;
        ListNode* previous_to_target = head;
        while (index < size - n - 1) {
            previous_to_target = previous_to_target->next;
            index += 1;
        }

        previous_to_target->next = previous_to_target->next->next;

        return head;
    }
};
