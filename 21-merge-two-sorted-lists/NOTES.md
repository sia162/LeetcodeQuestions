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
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
if(list1 == NULL) return list2;
if(list2 == NULL) return list1;
if(list1->val<=list2->val){
list1->next = mergeTwoLists(list1->next,list2);
return list1;
}else{
list2->next = mergeTwoLists(list2->next,list1);
return list2;
}
}
};
```
​
​
***NON recursive approch***
```
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
ListNode* start = new ListNode(0);
ListNode* temp = start;
while(list1!=NULL && list2!=NULL){
if(list1->val<=list2->val){
temp->next = list1;
temp = temp->next;