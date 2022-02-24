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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        vector<int> v;
        
        ListNode* temp = head;
        while(temp){ v.push_back(temp->val); temp=temp->next;}
        sort(v.begin(),v.end());
        
        ListNode* newhead = new ListNode(v[v.size()-1]);
        
        for(int i=v.size()-2;i>=0;i--){
            ListNode* node = new ListNode(v[i],newhead);
            newhead = node;
        }
        
        return newhead;
    }
};