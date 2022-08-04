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


/*
-assign a dummy node to null
-create a next node, point it to the next of head node
-head->next = dummy
-dummy = head
-head = next






*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* p = head;
        ListNode* q = NULL;
        ListNode* r = NULL;
        while(p){
            q = r;
            r = p;
            p = p->next;
            r->next = q;
        }
        return r;
    }
};