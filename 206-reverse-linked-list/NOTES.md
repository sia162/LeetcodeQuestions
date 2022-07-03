```
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/
class Solution {
public:
ListNode* reverseList(ListNode* head) {
//recurive approch
if(head == NULL || head->next == NULL) return head;
ListNode* newhead = reverseList(head->next);
ListNode* headnext = head->next;
headnext->next = head;
head->next = NULL;
return newhead;
//iterative approch
//         ListNode* prev = NULL;
//         ListNode* curr = head;
//         ListNode* nxt;
//         while(curr!=NULL){
//             nxt = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = nxt;
//         }
//         return prev;
}
};
```