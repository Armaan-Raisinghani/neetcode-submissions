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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy;
        dummy.next = head;
        ListNode* grp_prev = &dummy;
        ListNode* node = head;
        while (true) {
            ListNode* tmp = node;
            for (int i = 0; i < k - 1; i++)
                if (tmp) tmp = tmp->next;
            if (!tmp) {
                grp_prev->next = node;
                break;
            }
            ListNode* grp_head = node;
            ListNode* prev = nullptr;
            for (int i = 0; i < k; i++) {
                ListNode* next = node->next;
                node->next = prev;
                prev = node;
                node = next;
            }
            grp_prev->next = prev;
            grp_prev = grp_head;
        }
        return dummy.next;
    }
};
