/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    // DFS recursive solution using DFS
   public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return root;
        }
        TreeNode *left = root->left, *right = root->right;
        root->left = invertTree(right);
        root->right = invertTree(left);
        return root;
    }
};

class Solution2 {
    // DFS iterative solution using Stack
   public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return root;
        }

        stack<TreeNode*> stk;
        stk.push(root);

        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();
            TreeNode* left = node->left;
            node->left = node->right;
            node->right = left;

            if (node->left) {
                stk.push(node->left);
            }
            if (node->right) {
                stk.push(node->right);
            }
        }

        return root;
    }
};

class Solution3 {
    // BFS iterative solution using Queue
   public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return root;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            TreeNode* left = node->left;
            node->left = node->right;
            node->right = left;

            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }

        return root;
    }
};
