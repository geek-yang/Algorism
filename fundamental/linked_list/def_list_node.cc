#include <iostream>
using namespace std;

// https://www.tutorialspoint.com/create-linked-list-from-a-given-array-in-cplusplus-program

struct ListNode {
    int val; // value
    ListNode *next; // pointer
    ListNode(int x) : val(x), next(NULL) {}  //constructor
};

void print_list(ListNode* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
};

int main () {
    // create three empty nodes
    ListNode* head = new ListNode(5);
    head->next = nullptr;
    ListNode* second = new ListNode(3);
    second->next = nullptr;
    ListNode* third = new ListNode(1);
    third->next = nullptr;

    // link these nodes
    head->next = second;
    second->next = third;

    // print link list

    print_list(head);
}