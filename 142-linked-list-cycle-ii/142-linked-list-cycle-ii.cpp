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
-use hashtable to solve, insert all nodes, if already found, cycle exists, return that node
-tc -> o(1)
-sc -> o(n)
        unordered_set<ListNode*> nodes;
        ListNode *temp = head;
        while(temp != NULL){
            if(nodes.find(temp) != nodes.end()){
                return temp;
            }
            nodes.insert(temp);
            temp = temp->next;
        }
        return NULL;
 
-slow and fast pointer moethod
-find the collision pt
-entry pointer at the head, move both entry plus slow by 1 step
-the node at which they collide, will be the req node

*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *temp = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                while(slow != temp){
                    slow = slow->next;
                    temp = temp->next;
                }
                return slow;
            }
        }        
        return NULL;
    }
};