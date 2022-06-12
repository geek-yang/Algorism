#include <iostream>
using namespace std;

struct ListNode {
    int val; // value
    ListNode *next; // pointer
    ListNode(int x) : val(x), next(NULL) {}  //constructor
};

int main () {
    ListNode node_1(2);
    cout << node_1.val << "\n" << node_1.next << endl;
}