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
   private:
    int diameter = 0;

    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);

        diameter = max(diameter, maxLeft + maxRight);

        return max(maxLeft, maxRight) + 1;
    }

   public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);

        return diameter;
    }
};
