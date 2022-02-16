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
    void reorderList(ListNode* head) {
        
        if(head->next != NULL && head->next->next != NULL)
            {ListNode* temp = head;
            vector<ListNode*> v;

            while(temp!=NULL){
                v.push_back(temp);    
                temp=temp->next;
            }

            temp = head;
            ListNode* node = head->next;

            int n = 1;
            int i = v.size()-1;
            while(n<=v.size()){
                temp->next = v[i];
                temp->next->next = node;
                temp = temp->next->next;
                node = node->next;
                i--;
                n = n+2;
            }

            node->next = NULL;}
        
    }
};