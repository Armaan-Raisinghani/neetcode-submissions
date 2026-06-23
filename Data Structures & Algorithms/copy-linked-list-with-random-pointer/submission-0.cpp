/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> hash;
        Node deep_copy(0);
        Node* copy_head = &deep_copy;
        Node* start = head;
        while(start){
            copy_head->next = new Node(start->val);
            hash[start] = copy_head->next;
            copy_head = copy_head->next;
            start = start->next;
        }
        copy_head = deep_copy.next;
        start = head;
        while(copy_head){
            copy_head->random = hash[start->random];
            copy_head = copy_head->next;
            start = start->next;
        }
        return deep_copy.next;
    }
};
