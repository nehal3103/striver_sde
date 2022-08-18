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
-hashing
-if the same node is found in the hashset, return true
-tc -> o(n)
-sc -> o(n)
bool ans = false;
        ListNode *temp = head;
        unordered_set<ListNode*> nodes;
        while(temp != NULL){
            if(nodes.find(temp) != nodes.end())
                ans = true;
            else
                nodes.insert(temp);
            temp = temp->next;
        }
        return ans;
        
-optimal approach
-take two pointers - slow, fast
-move slow by 1 pos, fast by 2 pos
-if they collide, they form a cycle
-tc -> o(n)
-sc -> o(1)
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return false;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                return true;
            }
        }
        return false;
    }
};