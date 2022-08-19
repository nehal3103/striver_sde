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
-brute force
-take all the elements and store them in an array or vector
-check if it is a palindrome or not
-tc -> o(n)
-sc -> o(n)
vector<int> v;
        ListNode* temp = head;
        while(temp != NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }
        bool ans = true;
        int n = v.size();
        for(int i = 0; i <= n/2; i++){
            if(v[i] != v[n-i-1]){
                ans = false;
                break;
            }                        
        }        
        return ans;  
        
-better solution
-find the middle of the ll
-reverse the right half of the linked list
-check if left and right are equal using two pointer approach
-tc -> o(n)
-sc -> o(1)
*/
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* pre = NULL;
        ListNode* next = NULL;
        while(head != NULL){
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = reverse(slow->next); 
        slow = slow->next;
        ListNode* dummy = head;
        while(slow != NULL){
            if(slow->val != dummy->val){
                return false;
            }
            dummy = dummy->next;
            slow = slow->next;
        }
        return true;
    }
};