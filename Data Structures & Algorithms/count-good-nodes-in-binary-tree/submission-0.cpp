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
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        int m = 0;
        vector<TreeNode*> q = {root};
        vector<int> q_m = {root->val};
        while (q.size()) {
            TreeNode* back = q.back();
            int currMax = q_m.back();
            q.pop_back();
            q_m.pop_back();
            if (back->val >= currMax) m += 1;
            if (back->left) {
                q.push_back(back->left);
                q_m.push_back(max(back->left->val, currMax));
            }
            if (back->right) {
                q.push_back(back->right);
                q_m.push_back(max(back->right->val, currMax));
            }
        }
        return m;
    }
};
