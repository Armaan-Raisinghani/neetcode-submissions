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
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<TreeNode*>> nodes;
        int i = 0;
        nodes.push_back({root});
        if (!root) return {};
        while (nodes[i].size()) {
            nodes.push_back({});
            for (TreeNode* vec : nodes[i]) {
                if (vec) {
                    if (vec->left) nodes[i + 1].push_back(vec->left);
                    if (vec->right) nodes[i + 1].push_back(vec->right);
                }
            }
            i++;
        }
        vector<int> vals = {};
        for (auto& vec : nodes) {
            if (vec.size()) vals.push_back(vec.back()->val);
        }
        return vals;
    }
};
