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
        
-hashing
-store the addresses of all the nodes of ll1 in the hashset
-traverse in the other ll, if any is found, return that node
-tc - o(n+m)
-sc - o(n)
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
        
-optimized
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        int length1 = 0;
        int length2 = 0;
        while(temp1 != NULL || temp2 != NULL){
            if(temp1 != NULL){
                length1++;
                temp1 = temp1->next;
            }
            if(temp2 != NULL){
                length2++;
                temp2 = temp2->next;
            }
        }
        temp1 = headA;
        temp2 = headB;
        int diff = length1-length2;
        if(diff > 0){
            while(int i = 0 < diff){
                temp1 = temp1->next;
                i++;
            }
            while(temp1 != NULL){  
                if(temp1 == temp2){
                    return temp1;
                }
                temp1 = temp1->next;
                temp2 = temp2->next;
            }            
        }
        else{
            while(int i = 0 < diff){
                temp2 = temp2->next;
                i++;
            }
            while(temp2 != NULL){  
                if(temp2 == temp1){
                    return temp2;
                }
                temp1 = temp1->next;
                temp2 = temp2->next;
            }           
        }
        return NULL;
tc - o(m) + o(m-n) + o(n) - o(2m), m = length of bigger

-optimized ii

*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL){
            return NULL;
        }
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        while(temp1 != temp2){
            temp1 = temp1 == NULL? headB : temp1->next;
            temp2 = temp2 == NULL? headA : temp2->next;
        }        
        return temp1;
    }
};