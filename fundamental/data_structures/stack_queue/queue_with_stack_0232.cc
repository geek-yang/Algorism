#include <iostream>
#include <stack>
using namespace std;


class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;
    MyQueue () {
    }

    void push(int x) {
        stIn.push(x);
    }
    
    int pop() {
        int result = this->peek();
        stOut.pop();
        return result; 
    }
    
    int peek() {
        if (stOut.empty()) {
            while(!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        return stOut.top();
    }
    
    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};

int main () {
    MyQueue queue;
    cout << queue.empty() << endl;
    int x = 2;
    queue.push(x);
    cout << queue.peek() << endl;
    stack<int> test;
    cout << test.top() << endl;
    
    return 0;
}