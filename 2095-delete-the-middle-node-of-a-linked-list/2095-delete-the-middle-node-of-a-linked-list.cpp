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
    ListNode* deleteMiddle(ListNode* head) {
        
//         n -> even === mid = n/2 + 1
//         n -> odd === mid = (n-1)/2
            
//         [1,3,4,7,1,2,6]
        
        if(head->next == NULL) {
            delete(head);
            return NULL;
        }
        
        ListNode *slow = head,*fast = head;
        
        int count = 0;
        while(fast && fast->next!=NULL){
            if(count == 1) slow = slow->next;
            fast = fast->next->next;
            if(count == 0) count++;
        }
        
        cout<<slow->val<<" ";
        ListNode* temp = slow; //node before the one to be deleted
        slow = slow->next; //to be deleted;
        temp->next = slow->next;
        delete(slow);
        
        
        return head;
    }
};