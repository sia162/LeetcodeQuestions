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
    int pairSum(ListNode* head) {
        
        vector<int> list;
        ListNode* temp = head;
        
        while(temp!=NULL){
            list.push_back(temp->val);
            temp=temp->next;
        }
        
        int twinmaxsum = INT_MIN;
        for(int i=0,j=list.size()-1;i<j;i++,j--){
            twinmaxsum = max(list[i]+list[j] , twinmaxsum);
        }
        
        return twinmaxsum;
    }
};