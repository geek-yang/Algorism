#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelTraversal(TreeNode* head) {
        queue<TreeNode*> node_queue;
        if (head != NULL) node_queue.push(head);
        vector<vector<int>> result;
        while (!node_queue.empty()) {
            vector<int> temp_result;
            int queue_size = node_queue.size();
            for (int i = 0; i < queue_size; i++) {
                TreeNode* cur = node_queue.front();
                node_queue.pop();
                temp_result.push_back(cur->val);
                if (cur->left) node_queue.push(cur->left);
                if (cur->right) node_queue.push(cur->right);
            }
            result.push_back(temp_result);
        }
        return result;
    }
};

int main () {
    // create a sample tree
    TreeNode* root = new TreeNode(3);
    TreeNode* node_0 = new TreeNode(9);
    TreeNode* node_1 = new TreeNode(20);
    TreeNode* node_2 = new TreeNode(15);
    TreeNode* node_3 = new TreeNode(7);
    root->left = node_0;
    root->right = node_1;
    node_1->left = node_2;
    node_1->right = node_3;

    vector<vector<int>> result;
    Solution solver;
    result = solver.levelTraversal(root);
    for (auto &i: result) {
        for (auto &j: i) cout << j << ' ';
        cout << endl;
    }

    return 0;
}