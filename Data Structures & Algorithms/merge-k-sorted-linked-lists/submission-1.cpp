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
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> h;
        for (int i = 0; i < lists.size(); i++)
            if (lists[i]) h.push({lists[i]->val, i});
        while (!h.empty()) {
            auto m = h.top();
            root->next = lists[m.second];
            lists[m.second] = lists[m.second]->next;
            root = root->next;
            root->next = nullptr;
            h.pop();
            if (lists[m.second]) h.push({lists[m.second]->val, m.second});
        }
        return q.next;
    }
};
