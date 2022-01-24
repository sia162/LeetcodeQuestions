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
    int getDecimalValue(ListNode* head) {  
        string s{};
        while(head!=NULL){
            s += head -> val + '0';
            head=head->next;
        }
        cout<<s<<" ";
        return stoull(s,0,2); //s->string 2->base
    }
};