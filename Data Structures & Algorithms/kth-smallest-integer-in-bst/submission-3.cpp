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
    int kthSmallest(TreeNode* root, int k) {
        cnt = 0;
        ans = nullptr;
        inorder(root, k);
        return ans->val;
    }
    void inorder(TreeNode* node, int k) {
        if (!node || ans) return;
        inorder(node->left, k);
        if (++cnt == k) {
            ans = node;
            return;
        }
        inorder(node->right, k);
    }
    int cnt = 0;
    TreeNode* ans;
};
