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
private:
    struct CompareListNodes {
        bool operator()(ListNode* j1, ListNode* j2) {
            if (j1 == nullptr || j2 == nullptr) {
                return false;
            }
            return j1->val > j2->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CompareListNodes> pq;
        for (int i = 0, n = lists.size(); i < n; i++) {
            ListNode* node = lists[i];
            while (node != nullptr) {
                pq.push(node);
                node = node->next;
            }
        }
        if (pq.empty()) {
            return nullptr;
        }
        ListNode* ans = pq.top();
        pq.pop();
        ListNode* curr = ans;
        while (!pq.empty()) {
            curr->next = pq.top();
            pq.pop();
            curr = curr->next;
        }
        curr->next = nullptr;
        return ans;
    }
};
