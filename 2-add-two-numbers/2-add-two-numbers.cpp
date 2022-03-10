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
            ListNode* node2 = new ListNode();
            int sum = l1->val + l2->val + carry;
            l1 = l1->next;
            l2 = l2->next;
            
            if(sum>9){
                carry = 1;
            }else{
                carry = 0;
            }
                node2->val = sum%10;
                node->next = node2;
                node = node2;
        }
        
        while(l1!=NULL){
            ListNode* node2 = new ListNode();
            int sum = l1->val + carry;
            l1 = l1->next;
            
            if(sum>9){
                carry = 1;
            }else{
                carry = 0;
            }
                node2->val = sum%10;
                node->next = node2;
                node = node2;
        }
        
         while(l2!=NULL){
            ListNode* node2 = new ListNode();
            int sum =l2->val + carry;
            l2 = l2->next;
            
            if(sum>9){
                carry = 1;
            }else{
                carry = 0;
            }
                node2->val = sum%10;
                node->next = node2;
                node = node2;
        }
        
        if(carry == 1){
            ListNode* node2 = new ListNode();
            node2->val = 1;
            node->next = node2;
            node = node2;
        }
        
        
        return head->next;
    }
            
};