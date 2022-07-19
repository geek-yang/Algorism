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
        return cur->val;
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
        if (index > _size) return;
        ListNode* node = new ListNode(val);
        ListNode* cur = _dummyhead;
        while (index--) {
            cur = cur->next;
        }
        node->next = cur->next;
        cur->next = node;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= _size || index < 0) return;
        ListNode* cur = _dummyhead;
        while (index--) {
            cur = cur->next;
        }
        ListNode* temp = cur->next; // to release memory
        cur->next = cur->next->next;
        delete temp;
        _size--;
    }

    void printList() {
        ListNode* cur = _dummyhead;
        while (cur->next != nullptr) {
            cur = cur->next;
            cout << cur->val << ' ';
        }
        cout << endl;
    }

private:
    ListNode* _dummyhead;
    int _size;
};

int main () {
    // test case 1
    MyLinkedList* myLinkedList_1 = new MyLinkedList();
    myLinkedList_1->addAtHead(1);
    myLinkedList_1->printList();
    myLinkedList_1->addAtTail(3);
    myLinkedList_1->printList();
    myLinkedList_1->addAtIndex(1, 2);
    myLinkedList_1->printList();
    myLinkedList_1->deleteAtIndex(1);
    myLinkedList_1->printList();
    // test case 2
    cout << '\n' << endl;
    MyLinkedList* myLinkedList_2 = new MyLinkedList();
    myLinkedList_2->addAtHead(7);
    myLinkedList_2->printList();
    myLinkedList_2->addAtHead(2);
    myLinkedList_2->printList();
    myLinkedList_2->addAtHead(1);
    myLinkedList_2->printList();
    myLinkedList_2->addAtIndex(3, 0);
    myLinkedList_2->printList();
    myLinkedList_2->deleteAtIndex(2);
    myLinkedList_2->printList();
    myLinkedList_2->addAtHead(6);
    myLinkedList_2->printList();
    myLinkedList_2->addAtTail(4);
    myLinkedList_2->printList();
    int result = myLinkedList_2->get(4);
    cout << result << endl;
}