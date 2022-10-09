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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int result, digit, carry = 0;

        ListNode *head = nullptr, *tmp = nullptr, *trav = nullptr;

        while (true) {
            if (l1 == nullptr && l2 != nullptr)
                result = l2->val + carry;
            else if (l1 != nullptr && l2 == nullptr)
                result = l1->val + carry;
            else
                result = l1->val + l2->val + carry;

            digit = result % 10;
            carry = result / 10;

            if (head == nullptr) {
                head = new ListNode(digit);
                trav = head;
            } else {
                tmp = new ListNode(digit);
                trav->next = tmp;
                trav = tmp;
            }

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            if (l1 == nullptr && l2 == nullptr) break;
        }

        if (carry) {
            tmp = new ListNode(carry, nullptr);
            trav->next = tmp;
        }

        return head;
    }
};
