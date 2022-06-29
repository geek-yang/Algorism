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
    void traversal (TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        vec.push_back(cur->val);
        traversal(cur->left, vec);
        traversal(cur->left, vec);
    }

    vector<int> preorderTraversal (TreeNode *root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
    
};

int main () {
    return 0;
}