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
        
//         n -> even === mid = n/2
//         n -> odd === mid = (n-1)/2 - 1
            
//         [1,3,4,7,1,2,6]
        if(head->next == NULL) {
            delete(head);
            return NULL;
        }
        
        ListNode *slow = head,*fast = head->next->next;
        
        while(fast && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = slow->next->next;
        return head;
    }
};