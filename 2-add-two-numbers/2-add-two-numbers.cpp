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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* head = new ListNode();
        ListNode* node = head;
        
        int carry = 0;
        while(l1!=NULL && l2!=NULL){
            int sum = l1->val + l2->val + carry;
            l1 = l1->next;
            l2 = l2->next;
            
            if(sum>9){
                sum = sum%10;
                carry = 1;
            }else{
                carry = 0;
            }
            
            ListNode* n = new ListNode(sum);
            node->next = n;
            node = node->next;
        }
        
        while(l1!=NULL){
            int sum = l1->val + carry;
            l1 = l1->next;
            
            if(sum>9){
                sum = sum%10;
                carry = 1;
            }else{
                carry = 0;
            }
            
            ListNode* n = new ListNode(sum);
            node->next = n;
            node = node->next;
        }
        
         while(l2!=NULL){
            int sum = l2->val + carry;
            l2 = l2->next;
            
            if(sum>9){
                sum = sum%10;
                carry = 1;
            }else{
                carry = 0;
            }
            
            ListNode* n = new ListNode(sum);
            node->next = n;
            node = node->next;
        }
        
         if(carry){
             ListNode* n = new ListNode(carry);
            node->next = n;
            node = node->next;
        }
        
        return head->next;
            
        
    }
            
};