/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode q;
        ListNode* root = &q;
        while (true) {
            int m = -1;
            for (int i = 0; i < lists.size(); i++)
                if (lists[i] && (m == -1 || lists[i]->val < lists[m]->val)) m = i;
            if (m == -1) break;
            root->next = lists[m];
            lists[m] = lists[m]->next;
            root = root->next;
            root->next = nullptr;
        }
        return q.next;
    }
};
