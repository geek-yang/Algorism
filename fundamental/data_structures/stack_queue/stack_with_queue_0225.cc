#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> queue_major;
    queue<int> queue_exchange;

    MyStack () {
    }

    void push (int x) {
        queue_major.push(x);
    }

    int pop () {
        int size = queue_major.size() - 1;
        while (size--) {
            queue_exchange.push(queue_major.front());
            queue_major.pop();
        }
        int result = queue_major.front();
        queue_major.pop();
        queue_major = queue_exchange;
        while (!queue_exchange.empty()) {
            queue_exchange.pop();
        }

        return result;
    }

    int top () {
        int size = queue_major.size() - 1;
        while (size--) {
            queue_exchange.push(queue_major.front());
            queue_major.pop();
        }
        int result = queue_major.front();
        queue_exchange.push(queue_major.front());
        queue_major = queue_exchange;
        while (!queue_exchange.empty()) {
            queue_exchange.pop();
        }

        return result;
    }

    bool empty () {
        return queue_major.empty();
    }
};

int main () {
    MyStack mystack;
    cout << mystack.empty() << endl;
    mystack.push(2);
    cout << mystack.top() << endl;
    cout << mystack.pop() << endl;
    cout << mystack.empty() << endl;



    return 0;
}