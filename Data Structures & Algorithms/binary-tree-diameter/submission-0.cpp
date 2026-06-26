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
   public:
    int m = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return m;
    }
    int maxDepth(TreeNode* root) {
        if (root) {
            if (root->left || root->right) {
                int l = (root->left ? maxDepth(root->left) : 0);
                int r = (root->right ? maxDepth(root->right) : 0);
                m = max(m, l + r);
                return max(l, r) + 1;
            } else
                return 1;
        } else
            return 0;
    }
};