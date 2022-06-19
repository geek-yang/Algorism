#include <iostream>

// Definition for singly-linked list
// leetcode question 203

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {};
    ListNode(int x): val(x), next(nullptr) {};
    ListNode(int x, ListNode *next): val(x), next(next) {};
};

class Solution {
public:
    ListNode* removeElement (ListNode* head, int val) {
        // delete head node
        while (head != NULL && head->val == val) {
            ListNode* tmp = head;
            head = head->next; // pointer move to next node
            delete tmp;
        }

        // delete other nodes
        ListNode* cur = head;
        while(cur != NULL && cur->next != NULL) {
            if (cur->next->val == val) {
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            }
            else {
                cur = cur->next;
            }
        }

        return head;
    }
};

// Function to insert node
void insert(ListNode** head, int val)
{
    ListNode* temp = new ListNode;
    ListNode* ptr;
    temp->val = val;
    temp->next = NULL;
 
    if (*head == NULL)
        *head = temp;
    else {
        ptr = *head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}

ListNode *arrayToList(int arr[], int size)
{
    ListNode *head = NULL;
    for (int i = 0; i < size; i++)
        insert(&head, arr[i]);
    return head;
};

void print_list(ListNode* node) {
    while (node != NULL) {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << "The linked list is printed." << std::endl;
};

int main () {
    // test case 1
    std::cout << "Test case 1" << std::endl;
    int array_1[] = {1,2,6,3,4,5,6};
    int val = 6;

    int size = sizeof(array_1)/sizeof(array_1[0]);

    ListNode *head = arrayToList(array_1, size);

    print_list(head);

    // remove given value
    Solution solver;
    head = solver.removeElement(head, val);
    std::cout << "Remove given element:" << val << std::endl;
    print_list(head);

    // test case 2
    std::cout << "Test case 2" << std::endl;
    int array_2[] = {7,7,7,7};
    val = 7;

    size = sizeof(array_2)/sizeof(array_2[0]);

    head = arrayToList(array_2, size);

    print_list(head);

    // remove given value
    head = solver.removeElement(head, val);
    std::cout << "Remove given element:" << val << std::endl;
    print_list(head);

    return 0;
}