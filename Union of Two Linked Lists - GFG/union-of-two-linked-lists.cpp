//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};


// } Driver Code Ends
/*
// structure of the node is as follows

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

*/
class Solution
{
    public:

    Node* merge(Node* a, Node* b) {
        if (a == nullptr) return b;
        if (b == nullptr) return a;

        Node* ans = nullptr;

        if (a->data < b->data) {
            ans = a;
            ans->next = merge(a->next, b);
        } else if (b->data < a->data) {
            ans = b;
            ans->next = merge(a, b->next);
        } else {
            ans = a;
            ans->next = merge(a->next, b->next);
        }

        return ans;
    }
    
    Node* sort(Node* head) {
        if (head == nullptr || head->next == nullptr) return head;

        Node* slow = head;
        Node* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        Node* mid = slow;
        Node* nextToMid = mid->next;
        mid->next = nullptr;

        Node* first = sort(head);
        Node* second = sort(nextToMid);

        Node* ans = merge(first, second);

        return ans;
    }
    
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        // code here
        Node* merged = merge(head1, head2);
        Node* sorted = sort(merged);
        return sorted;
    }
};


//{ Driver Code Starts.

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends