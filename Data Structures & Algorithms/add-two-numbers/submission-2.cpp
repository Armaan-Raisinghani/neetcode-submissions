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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode* sum = &head;
        int carry = 0;
        while(l1||l2){
            int new_val = (l1? l1->val : 0) + (l2 ? l2->val : 0) + carry; 
            carry = 0;
            if (new_val>=10){
                carry = 1;
            }
            new_val = new_val%10;
            sum->next = new ListNode(new_val);
            sum = sum->next;
            l1 = l1?l1->next:l1;
            l2 = l2?l2->next:l2;
        }
        if (carry == 1){
            sum->next = new ListNode(1);
            sum = sum->next;
        }
        return head.next;
    }
};
