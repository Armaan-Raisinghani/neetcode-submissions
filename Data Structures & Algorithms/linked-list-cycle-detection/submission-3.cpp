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
    bool hasCycle(ListNode* head) {
        ListNode* head_s = head;
        ListNode* head_f = head;
        if(head==nullptr) return false;
        while(head_f->next!=nullptr && head_f->next->next!=nullptr){
            head_f = head_f->next->next;
            head_s = head_s->next;
            if(head_f==head_s) return true;
        }
        return false;
    }
};
