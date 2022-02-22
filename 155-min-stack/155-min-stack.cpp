class minNode{
    public: 
    int data;
    int minele;
    minNode* next = NULL;
};

minNode* head;

class MinStack {
public:
    MinStack(){ head = NULL; }
    
    void push(int val) {
        minNode* node = new minNode();
        node->data = val;
        node->next = head;
        
        if(head) node->minele = min(val, head->minele);
        else node->minele = val;
            
        head = node;
    }
    
    void pop() {
        head = head->next;
    }
    
    int top() {
        if(head == NULL) return NULL;
        return head->data;
    }
    
    int getMin() {  
        if(head == NULL) return NULL;
        return head->minele;
//         int minele = INT_MAX;
//         minNode* temp = head;
        
//         while(temp!=NULL){
//             minele = min(minele,temp->data);
//             temp = temp->next;
//         }
//         return minele;  
    } 
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */