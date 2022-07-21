
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
    
    ListNode* reverseIt(ListNode* head,ListNode* nullthing){
        if(head == nullthing || head->next == nullthing) return head;
        
        ListNode* newhead = reverseIt(head->next,nullthing);
        ListNode* headnext = head->next;
        headnext->next = head;
        head->next = nullthing;
        return newhead;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head==NULL || head->next == NULL || right == left) return head;
        
        ListNode* temp = head;
        
        ListNode* rightpointer=NULL,*leftpointer=NULL;
        int i=1;
        while(temp!=NULL) {
            if(i == left){
                leftpointer = temp;
            }
             if(i == right){
                rightpointer = temp;
                 break;
            }
            temp=temp->next;
            i++;
        }
        
        
        ListNode* nullthing;
        nullthing = rightpointer->next;
            
        ListNode* leftnode = leftpointer;
        ListNode* newheadofreversed = reverseIt(leftpointer,nullthing);
        
        if(leftnode!=head)
           { ListNode* temphead = head;
                while(temphead!=leftnode){
                    if(temphead->next == leftnode)
                        {temphead->next = newheadofreversed;
                        break;}

                    temphead = temphead->next;
                }
                return head;
            }
            
        return newheadofreversed;
    }
};
