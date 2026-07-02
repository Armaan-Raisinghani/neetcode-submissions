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
    bool isValidBST(TreeNode* root) {
        queue<vector<int>> vals;
        queue<TreeNode*> q;
        vals.push({-1001,1001});
        q.push(root);
        while (q.size()) {
            TreeNode* node = q.front();
            vector<int> minmax = vals.front();
            q.pop();
            vals.pop();
            if (node->val >= minmax[1] || node->val <= minmax[0]) return false;
            if (node->left) {
                q.push(node->left);
                vals.push({minmax[0], node->val});
            }
            if (node->right) {
                q.push(node->right);
                vals.push({node->val, minmax[1]});
            }
        }
        return true;
    }
};
