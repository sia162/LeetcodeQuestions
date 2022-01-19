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
    
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nxt;
        
        while(curr!=NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        return prev;
        
    }
 
    
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head,*fast = head;
        while(fast!=NULL && fast->next !=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        
        // 1 2 3 3 2 1 NULL
              // s     f 
        
        slow = reverse(slow);
        fast = head;
        
        // 1 2 3 1 2 3 NULL
        // f     s
        
        while(slow!=NULL){
            if(slow->val!=fast->val) return false;
            slow=slow->next;
            fast=fast->next;
        }
        
        return true;
        
    }
};