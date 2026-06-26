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
    int maxDepth(TreeNode* root) {
        if (root) {
            if (root->left || root->right) {
                return max((root->left ? maxDepth(root->left) : 0),
                           (root->right ? maxDepth(root->right) : 0)) +
                       1;
            } else
                return 1;
        } else return 0;
    }
};
