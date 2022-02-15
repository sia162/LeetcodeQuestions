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
        
        stack<int> s1;
        stack<int> s2;
        
        ListNode* temp = l1;
        while(temp!=NULL){
            s1.push(temp->val);
            temp=temp->next;
        }
        
        
        temp = l2;
         while(temp!=NULL){
            s2.push(temp->val);
            temp=temp->next;
        }
        
        
        ListNode* head = new ListNode(0);
        ListNode* node = head;
            
        int carry = 0;
        while(!s1.empty() && !s2.empty()){
            int sum = s1.top()+s2.top()+carry;
            // cout<<sum<<" ";
            s1.pop();
            s2.pop();
            if(sum>9){
                sum = sum%10;
                carry = 1;
            }else{
                carry = 0;
            }
        
            ListNode* n = new ListNode(sum);
            n->next = node->next;
            node->next = n;
        }
        
        
        while(!s1.empty()){
            int sum = s1.top() + carry;
            s1.pop();
            if(sum>9){
                sum = sum%10;
                carry = 1;
            }else{
                carry = 0;
            }
            
            ListNode* n = new ListNode(sum);
            n->next = node->next;
            node->next = n;
        }
        
        while(!s2.empty()){
            int sum = s2.top() + carry;
            s2.pop();
            if(sum>9){
                sum = sum%10;
                carry = 1;
            }else{
                carry = 0;
            }
            
           ListNode* n = new ListNode(sum);
            n->next = node->next;
            node->next = n;
        }
        
        if(carry){
            ListNode* n = new ListNode(carry);
            n->next = node->next;
            node->next = n;
        }
            
            
     return head->next;
        
    }
};