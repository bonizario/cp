#include <iostream>
#include <stack>

using namespace std;

class Queue {
   private:
    stack<int> s1, s2;

    void move_stacks() {
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

   public:
    void push(int x) {
        if (s1.empty() && s2.empty()) {
            s1.push(x);
        } else {
            s2.push(x);
        }
    }

    void pop() {
        if (s1.empty()) {
            move_stacks();
        }
        s1.pop();
    }

    void front() {
        if (s1.empty()) {
            move_stacks();
        }
        cout << s1.top() << "\n";
    }
};

int main() {
    int q, type, x;
    Queue queue;
    cin >> q;
    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> x;
            queue.push(x);
        } else if (type == 2) {
            queue.pop();
        } else {
            queue.front();
        }
    }
    return 0;
}
