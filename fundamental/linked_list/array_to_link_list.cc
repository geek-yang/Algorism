#include <iostream>

//https://www.geeksforgeeks.org/create-linked-list-from-a-given-array/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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

void print_list(ListNode* node) {
    while (node != NULL) {
        std::cout << node->val << " ";
        node = node->next;
    }
};

ListNode *arrayToList(int arr[], int size)
{
    ListNode *head = NULL;
    for (int i = 0; i < size; i++)
        insert(&head, arr[i]);
    return head;
};

int main () {
    // test case
    int array[] = {1,2,6,3,4,5,6};
    int val = 6;

    int size = sizeof(array)/sizeof(array[0]);

    ListNode *head = arrayToList(array, size);

    print_list(head);

    return 0;
}