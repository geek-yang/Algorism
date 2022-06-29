#include <iostream>
#include <vector>
using namespace std;

/* Leetcode question 144*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class Solution {
public:
    void preorder_traversal (TreeNode* cur, vector<int>& vec) {
        // preorder traversal
        if (cur == NULL) return;
        
        
    }
};

int main () {
    return 0;
}