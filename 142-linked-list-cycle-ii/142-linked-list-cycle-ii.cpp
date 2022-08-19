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
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
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
    }
};