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
    
    ListNode* reverseHalfList(ListNode* h){
        if(h->next == NULL) return h;
        
        ListNode* newhead = reverseHalfList(h->next);
        ListNode* headnext = h->next;
        
        headnext->next = h;
        h->next = NULL;
        return newhead;
    }
    
    
    int pairSum(ListNode* head) {
        ListNode* ptr1 = head;
        
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        
        if(fast == NULL) return head->val + head->next->val;
        
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = reverseHalfList(slow->next);
      
        // cout<<head->val<<" ";
        // cout<<slow->next->val;
        ListNode* ptr2 = slow->next;
        int maxtwinsum = INT_MIN;
        
         while(ptr2 != NULL){
            cout<<ptr1->val + ptr2->val<<" ";
            maxtwinsum = max((ptr1->val + ptr2->val) , maxtwinsum);
             ptr1 = ptr1->next;
             ptr2 = ptr2->next;
        }
        
       return maxtwinsum;
    }
};