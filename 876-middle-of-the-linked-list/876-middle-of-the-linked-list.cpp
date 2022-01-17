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
    ListNode* middleNode(ListNode* head) {
        
        
        // two pointer approch
        ListNode *onestep = head, *twostep = head;
        while(twostep && twostep->next!=NULL){
            onestep = onestep->next;
            twostep = twostep->next->next;
        }
        
        return onestep;
        
        
//brute force approch     
//         ListNode* temp;
//         temp = head;
//         int count = 1;
//         while(temp->next != NULL){
//             count++;
//             temp = temp->next;
//         }
        
//             // cout<<count<<" ";
//         if(count%2==0) count = count/2 + 1;
//         else count = (count+1)/2;
        
        
//         temp = head;    
//         while(count!=1){
//             count--;
//             temp = temp->next;
//         }
        
//         return temp;
        
    }
};