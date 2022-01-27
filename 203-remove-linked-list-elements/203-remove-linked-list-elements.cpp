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
    ListNode* removeElements(ListNode* head, int val) {
        
        while(head!=NULL && head->val == val){
            head = head->next;
        }
        
         if(head == NULL) return NULL;
        
        ListNode* back = head; //we know head won't have value == val
        ListNode* temp = head->next;
        
        while(temp!=NULL){
            if(temp->val == val){
                back->next = temp->next;
                temp = back->next;
            }else{
                temp = temp->next;
                back = back->next;
            }
        }
        
        return head;
        
    }
};