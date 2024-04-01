/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
class LRUCache {
   private:
    struct ListNode {
        int key;
        int val;
        ListNode *next;
        ListNode *prev;
    };

    int count, capacity;
    ListNode *head, *tail;
    unordered_map<int, ListNode *> cache;

    void addNodeToHead(ListNode *node) {
        node->prev = this->head;
        node->next = this->head->next;

        this->head->next->prev = node;
        this->head->next = node;
    }

    void removeNode(ListNode *node) {
        ListNode *prev = node->prev;
        ListNode *next = node->next;

        prev->next = next;
        next->prev = prev;
    }

    void moveNodeToHead(ListNode *node) {
        this->removeNode(node);
        this->addNodeToHead(node);
    }

    ListNode *popTail() {
        ListNode *lruNode = this->tail->prev;
        this->removeNode(lruNode);
        return lruNode;
    }

   public:
    LRUCache(int capacity) {
        this->count = 0;
        this->capacity = capacity;

        this->head = new ListNode();
        this->head->prev = nullptr;
        this->tail = new ListNode();
        this->tail->next = nullptr;

        this->head->next = this->tail;
        this->tail->prev = this->head;
    }

    int get(int key) {
        auto it = this->cache.find(key);

        if (it == this->cache.end()) {
            return -1;
        }

        ListNode *node = it->second;
        moveNodeToHead(node);
        return node->val;
    }

    void put(int key, int value) {
        auto it = this->cache.find(key);

        if (it == this->cache.end()) {
            ListNode *newNode = new ListNode();
            newNode->key = key;
            newNode->val = value;

            this->addNodeToHead(newNode);
            this->cache[key] = newNode;
            this->count += 1;

            if (this->count > this->capacity) {
                ListNode *lruNode = this->popTail();
                this->cache.erase(lruNode->key);
                this->count -= 1;
            }

        } else {
            ListNode *node = it->second;
            node->val = value;
            this->moveNodeToHead(node);
        }
    }
};
