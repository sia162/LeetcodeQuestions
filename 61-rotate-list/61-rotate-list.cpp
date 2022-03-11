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
    ListNode* rotateRight(ListNode* head, int k) {
        
        int n;
        if(head == NULL || head->next == NULL) return head;
        
        stack<ListNode*> prevst;
        queue<ListNode*> prevq;
        
        ListNode* prev = head;
        ListNode* last = head->next;
        ListNode* ahead = last->next;
        n=3;
        
        while(ahead!=NULL && ahead->next!=NULL){
            last = last->next;
            ahead = ahead->next;
            
            prevst.push(prev);
            prev = prev->next;
            n++;
        }
        
        // cout<<n<<" ";
        while(!prevst.empty()){
            prevq.push(prevst.top());
            prevst.pop();
        }
        
        
        
        if(ahead == NULL)
        {
            ahead = last;
            last = prev;
            
            if(k%2==0) return head;
            else{
                ahead->next = head;
                head = ahead;
                last->next = NULL;
                return head;
            }
        }else{
            
            if(k%n==0)
                return head;
            else{
                k=k%n;
            }
            
                while(k--){
                ahead->next = head;
                head = ahead;
                prevq.push(head);

                last->next = NULL;

                ahead = last;
                last = prev;
                prev = prevq.front();
                prevq.pop();
            }
        }
        
        
        
        return head;
        
    }
};