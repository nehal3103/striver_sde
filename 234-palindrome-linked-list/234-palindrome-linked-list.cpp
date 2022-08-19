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
*/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
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
    }
};