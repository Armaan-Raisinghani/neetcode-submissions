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
    bool isBalanced(TreeNode* root) {
        int m = maxDepth(root);
        if (m == -1) return false;
        return true;
    }
    int maxDepth(TreeNode* root) {
        if (root) {
            if (root->left || root->right) {
                int l = maxDepth(root->left);
                int r = maxDepth(root->right);
                if(l==-1 || r == -1) return -1;
                int d = l - r;
                if (d > 1 || d < -1) {
                    cout << root->val << endl;
                    return -1;
                };
                return max(l, r) + 1;
            } else
                return 1;
        } else
            return 0;
    }
};
