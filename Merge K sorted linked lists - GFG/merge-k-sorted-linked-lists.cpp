//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node* merger(Node* l1,Node* l2){
        Node* result = new Node(-1);
        Node* temp = result;
        
        while(l1!=NULL && l2!=NULL){
            if(l1->data <l2->data){
                temp->next = l1;
                l1 = l1->next;
                temp = temp->next;
            }else{
                temp->next = l2;
                l2 = l2->next;
                temp = temp->next;
            }
        }
        
        if(l1!=NULL){
            temp->next = l1;
        }
        
        if(l2!=NULL){
            temp->next = l2;
        }
        
        return result->next;
    }
    
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           if(K == 1) return arr[0];
           
           Node* l1 = arr[0];
           Node* l2 = arr[1];
           for(int i = 2;i<=K;i++){
               l1 = merger(l1,l2);
               l2 = arr[i];
           }
           
           return l1;
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends