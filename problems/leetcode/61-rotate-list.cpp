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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;

        ListNode* trav = head;
        int length = 0, prev, curr;
        while (trav->next != nullptr) {
            trav = trav->next;
            length++;
        }
        length++;
        k = k % length;

        ListNode* last = trav;
        trav->next = head;

        while (k--) {
            trav = head->next;
            prev = head->val;
            int i = length;
            while (i--) {
                curr = trav->val;
                trav->val = prev;
                prev = curr;
                trav = trav->next;
            }
        }

        last->next = nullptr;

        return head;
    }
};
