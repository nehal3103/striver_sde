/*
-traverse the ll to count the number of nodes
-make anoither traversal to find the mid node
-tc - o(n)
-sc - o(1)
        ListNode *temp = head;
        int count = 0;
        while(temp != NULL){
            temp = temp->next;
            count++;
        }
        int mid = count/2;
        temp = head;
        for(int i = 0; i < mid; i++){
            temp = temp->next;            
        }
        return temp;

-tortoise approach
-make two nodes - fast and slow tortoise, point them to head
-fast tortoise takes 2 steps, slow one takes 1 step
-when fast will either reach the node or cross the ll, we will stop the process, slow will be at the mid node

*/

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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};