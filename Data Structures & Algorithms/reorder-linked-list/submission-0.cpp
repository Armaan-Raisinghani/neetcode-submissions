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
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* node = head;
    while(node!=nullptr){
        ListNode* next = node->next;
        node->next = prev;
        prev = node;
        node = next;
    }
    return prev;
}
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        ListNode* list2 = reverseList(fast);
        ListNode* main = head;
        slow = head->next;
        while(slow){
            ListNode* t1 = slow;
            ListNode* t2 = list2;
            slow = slow->next;
            list2 = list2->next;
            main->next = t2;
            main->next->next = t1;
            main = main->next->next;
        }
        if(fast) main->next=list2;
    }
};