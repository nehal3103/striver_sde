/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
-brute force
-for every node in 1 ll, check if the same node exists in the other ll or not
-tc - o(n*m) - product of lengths
ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        ListNode *ans = NULL;
        while(temp1 != NULL){
            while(temp2 != NULL){
                if(temp1 == temp2){
                    ans = temp1;
                    temp2 = temp2->next;
                }
            }
            temp1 = temp1->next;
        }
        return ans;
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> address;
        ListNode *temp1 = headA;
        while(temp1 != NULL){
            address.insert(temp1);
            temp1 = temp1->next;
        }
        ListNode *temp2 = headB;
        while(temp2 != NULL){
            if(address.find(temp2) != address.end()){
                return temp2;
            }
            temp2 = temp2->next;
        }
        return NULL;
    }
};