#include <iostream>
using namespace std;

class MyLinkedList {
public:
    struct ListNode
    {
        int val;
        ListNode* next;
        ListNode (): val(0), next(nullptr) {};
        ListNode (int x): val(x), next(nullptr) {};
        ListNode (int x, ListNode *next): val(x), next(next) {};
    };

    MyLinkedList () {
        _dummyhead = new ListNode(0);
        _size = 0;
    }

    int get(int index) {
        if (index > (_size - 1)|| index < 0) return -1;
        ListNode* cur = _dummyhead -> next;
        while (index--) cur = cur -> next;
        return cur -> val;
    }
    
    void addAtHead(int val) {
        
    }
    
    void addAtTail(int val) {
        
    }
    
    void addAtIndex(int index, int val) {
        
    }
    
    void deleteAtIndex(int index) {
        
    }
private:
    ListNode* _dummyhead;
    int _size;
};

int main () {

}