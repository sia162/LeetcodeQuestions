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
        vector<int> binary;
        ListNode* temp = head;
        
        while(temp!=NULL){
            binary.push_back(temp->val);
            temp=temp->next;
        }
        
        int num = 0;
        int n = binary.size()-1;
        for(int i=n;i>=0;i--){
            num = num + binary[i]*pow(2,n-i);
        }
        
        return num;
    }
};