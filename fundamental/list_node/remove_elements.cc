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
        // tba
        return head;
    }
};

int main () {
    // test case
    std::vector<int> head{1,2,6,3,4,5,6};
    int val = 6;
}