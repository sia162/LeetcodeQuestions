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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head==NULL || head->next == NULL && n>=1) return NULL;
        if(head->next == NULL && n<1) return head;
        
        ListNode* temp = head;
        int size = 0;
        while(temp!=NULL){
            temp = temp->next;
            size++;
        }
        
        if(size == n){
            return head->next;
        }
        
        
        
        // cout<<size<<" ";
        int i = 1;
        temp = head;
        while(i<size-n){   
            temp = temp->next;
            i++;
        }
        
        if(n==1)
            temp->next=NULL;
        else
            temp->next = temp->next->next;
          

        return head;
    }
};