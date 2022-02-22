class minNode{
    public: 
    int data;
    minNode* next = NULL;
};
minNode* head;

class MinStack {
public:
   
    MinStack(){
        head = NULL;
    }
    
    void push(int val) {
        if(head == NULL){
            minNode* node = new minNode();
            node->data = val;
            head = node;
            return;
        }
        
        minNode* node = new minNode();
        node->data = val;
        node->next = head;
        head = node;
        return;
        
    }
    
    void pop() {
        if(head == NULL)
            return;
        
        head = head->next;
    }
    
    int top() {
        if(head==NULL)
            return NULL;
        
        return head->data;
    }
    
    int getMin() {
        if(head == NULL) return NULL;
        
        int minele = INT_MAX;
        minNode* temp = head;
        
        while(temp!=NULL){
            minele = min(minele,temp->data);
            temp = temp->next;
        }
        return minele;
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