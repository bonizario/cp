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
    ListNode *deleteDuplicates(ListNode *head) {
        // border case [] and [1]
        if (head == NULL || head->next == NULL) return head;
        ListNode *prev = head;
        ListNode *curr = prev->next;
        ListNode *lastOk = prev;
        bool repeated = false;
        while (true) {
            if (!repeated && prev->val == curr->val) {  // found duplicate
                repeated = true;
            } else if (repeated && prev->val != curr->val) {  // after duplicate
                repeated = false;

                // moves head to current node if the head value is duplicate
                if (head->val == prev->val) head = curr;

                // point previous valid node to current node
                lastOk->next = curr;
            } else if (!repeated) {
                lastOk = prev;  // moves lastOk to previous node
            }

            // stop loop if current node is the last node
            if (curr->next == NULL) break;
            prev = prev->next;
            curr = curr->next;
        }
        // border case [1,1]
        if (repeated && head->val == lastOk->next->val) return NULL;

        // border case [1,2,2]
        if (repeated) lastOk->next = NULL;

        return head;
    }
};
