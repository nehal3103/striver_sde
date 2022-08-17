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
-naive solution
ListNode *dummy = head;
        int count = 0;
        while(dummy != NULL){
            count++;
            dummy = dummy->next;
        }
        if(n == count){
            ListNode* node = head;
            head = head->next;
            delete node;
            return head;
        }
        int diff = count - n;
        dummy = head;
        count = 1;
        while(count != diff){
            count++;
            dummy = dummy->next;
        }
        ListNode *node = dummy->next;
        dummy->next = node->next;
        delete node;
        return head;
    }
-tc - o(2n)
-sc - o(1)
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *fast = dummy;
        ListNode *slow = dummy;
        int i = 0;
        while(i < n){
            fast = fast->next;
            i++;
        }
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *node = slow->next;
        slow->next = slow->next->next;
        delete node;
        return dummy->next;
    }
};