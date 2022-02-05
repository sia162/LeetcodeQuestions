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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multiset<int> ms;
        
        for(int i=0;i<lists.size();i++){
            ListNode* temp = lists[i];
            while(temp!=NULL){
                ms.insert(temp->val);
                temp=temp->next;
            } 
        }
        
        ListNode* ans = new ListNode(0);
        ListNode* res = ans;
        for(auto val:ms){
            ans->next=new ListNode(val);
            ans=ans->next;
        }
        
        return res->next;
        
    }
};