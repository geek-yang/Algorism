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
        ListNode* cur = _dummyhead->next;
        while (index--) cur = cur->next;
        return cur -> val;
    }
    
    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = _dummyhead->next;
        _dummyhead->next = node;
        _size++;
    }
    
    void addAtTail(int val) {
        ListNode* node = new ListNode(val);
        ListNode* cur = _dummyhead;
        while(cur->next != nullptr) cur = cur->next;
        cur->next = node;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < _size - 1 && index >= 0) {
            ListNode* node = new ListNode(val);
            ListNode* cur = _dummyhead;
            while (index--) {
                cur = cur->next;
            }
            node->next = cur->next;
            cur->next = node;
            _size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if (index >= _size || index < 0) {
            return;
        }

    }

    void printList() {
        ListNode* cur = _dummyhead;
        while (cur != nullptr) {
            cout << cur->val << ' ';
            cur = cur->next;
        }
        cout << '\n';
    }

private:
    ListNode* _dummyhead;
    int _size;
};

int main () {
    MyLinkedList* myLinkedList = new MyLinkedList();
    myLinkedList->addAtHead(1);
    myLinkedList->printList();
    myLinkedList->addAtTail(3);
    myLinkedList->printList();
    // myLinkedList->addAtIndex(1, 2); 
}