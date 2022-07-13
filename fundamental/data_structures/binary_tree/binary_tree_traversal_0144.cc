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

class Postorder {
public:
    void traversal (TreeNode* cur, vector<int>& vec) {
        if (cur == nullptr) return;
        traversal(cur->left, vec);
        traversal(cur->right, vec);
        vec.push_back(cur->val);
    }

    vector<int> postorderTraversal (TreeNode *root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};

class Inorder {
public:
    void traversal (TreeNode* cur, vector<int>& vec) {
        if (cur == nullptr) return;
        traversal(cur->left, vec);
        vec.push_back(cur->val);
        traversal(cur->right, vec);        
    }

    vector<int> inorderTraversal (TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;        
    }
};

class Preorder {
public:
    void traversal (TreeNode* cur, vector<int>& vec) {
        if (cur == nullptr) return;
        vec.push_back(cur->val);
        traversal(cur->left, vec);
        traversal(cur->right, vec);
    }

    vector<int> preorderTraversal (TreeNode *root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};

int main () {
    // create a sample tree
    TreeNode* root = new TreeNode(10);
    TreeNode* node_0 = new TreeNode(1);
    TreeNode* node_1 = new TreeNode(2);
    TreeNode* node_2 = new TreeNode(3);
    TreeNode* node_3 = new TreeNode(4);
    root->left = node_0;
    root->right = node_3;
    node_0->left = node_1;
    node_0->right = node_2;

    // create a vector to save the results

    vector<int> tree_traversal_result;
    cout << "Preorder traversal" << endl;
    Preorder solver;
    tree_traversal_result = solver.preorderTraversal(root);
    for (auto &i: tree_traversal_result) {
        cout<< i << ' ';
    }

    cout << "\n" << "Postorder traversal" << endl;
    Postorder solver_1;
    tree_traversal_result = solver_1.postorderTraversal(root);
    for (auto &i: tree_traversal_result) {
        cout<< i << ' ';
    }

    cout << "\n" << "Inorder traversal" << endl;
    Inorder solver_2;
    tree_traversal_result = solver_2.inorderTraversal(root);
    for (auto &i: tree_traversal_result) {
        cout<< i << ' ';
    }

    return 0;
}