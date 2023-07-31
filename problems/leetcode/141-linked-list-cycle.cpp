class Solution {
   public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr) {
            return false;
        }
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};
