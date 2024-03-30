/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }

        // linked list with only one node
        if (!head->next) {
            Node* new_head = new Node(head->val);
            new_head->random = head->random ? new_head : nullptr;
            new_head->next = nullptr;
            return new_head;
        }

        // map original list node indexes
        int index = 0;
        Node* p1 = head;
        unordered_map<Node*, int> indexes;
        while (p1) {
            indexes[p1] = index;
            p1 = p1->next;
            index += 1;
        }

        // map all the random pointers using only indexes
        index = 0;
        p1 = head;
        unordered_map<int, int> random;
        while (p1) {
            random[index] = (p1->random == nullptr ? -1 : indexes[p1->random]);
            p1 = p1->next;
            index += 1;
        }

        // duplicate the original list and map the new list indexes
        p1 = head->next;
        Node *new_head = new Node(head->val), *p2 = new_head;
        unordered_map<int, Node*> nodes = {{0, new_head}};
        index = 1;
        while (p1) {
            Node* new_node = new Node(p1->val);
            nodes[index] = new_node;
            p2->next = new_node;
            new_node->next = nullptr;
            p1 = p1->next;
            p2 = new_node;
            index += 1;
        }

        // link the random pointers in the new list
        index = 0;
        p2 = new_head;
        while (p2) {
            p2->random = (random[index] == -1 ? nullptr : nodes[random[index]]);
            p2 = p2->next;
            index += 1;
        }

        return new_head;
    }
};
