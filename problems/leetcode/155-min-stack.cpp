class MinStack {
   private:
    class Node {
       public:
        int val;
        int min_val;
        Node* next;

        Node(int val, int min_val, Node* next) {
            this->val = val;
            this->min_val = min_val;
            this->next = next;
        }
    };
    Node* head = nullptr;

   public:
    MinStack() {}

    void push(int val) {
        if (head == nullptr) {
            head = new Node(val, val, nullptr);
        } else {
            head = new Node(val, min(val, head->min_val), head);
        }
    }

    void pop() {
        head = head->next;
    }

    int top() {
        return head->val;
    }

    int getMin() {
        return head->min_val;
    }
};
