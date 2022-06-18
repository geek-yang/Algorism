#include <iostream>
#include <vector>

 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // delete head node
        while (head != NULL && head->val == val) {
            ListNode* tmp = head;
            head = head->next; // pointer move to next node
            delete tmp;
        }
        return head;

        // delete other nodes
    }
};

int main () {
    // test case
    int array = {1,2,6,3,4,5,6};
    int val = 6;
}