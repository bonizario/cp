class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        ListNode *next, *prev = nullptr;
        while (head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
