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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<TreeNode*>> nodes;
        vector<vector<int>> vals;
        int i = 0;
        nodes.push_back({root});
        if (!root) return {};
        while (nodes[i].size()) {
            vals.push_back({});
            nodes.push_back({});
            for (TreeNode* vec : nodes[i]) {
                if (vec) {
                    vals[i].push_back({vec->val});
                    if (vec->left) nodes[i + 1].push_back(vec->left);
                    if (vec->right) nodes[i + 1].push_back(vec->right);
                }
            }
            i++;
        }
        return vals;
    }
};
