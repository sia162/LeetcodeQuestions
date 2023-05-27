//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
    // function to construct tree from string
    map<int,int> m;
    void mapping(string s){
        stack<int> st;
        
        for(int i=0;i<s.length();i++){
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')'){
                m[st.top()] = i;
                st.pop();
            }
        }
    }
    
    bool isDigit(char ch){
        return (ch<='9' && ch>='0');
    }
    
    Node* rec(string str,int si,int ei){
        //base
        if(si>ei) return NULL;
        
        //recursive
         int num=0; //root
         while(si<str.length() && isDigit(str[si])){
             int x = str[si]-'0';
             num=num*10+x;
             si++;
         }
         si--;
         
         
         Node* root = new Node(num);
         int y=-1;
         if(si+1<ei && str[si+1] == '('){
             y=m[si+1];
         }
         
         if(y!=-1){
             root->left = rec(str,si+2,y-1);
             root->right = rec(str,y+2,ei-1);
         }
         
         return root;
    }
    
    
    
    Node *treeFromString(string str){
        // code here
        mapping(str);
        //now we have starting ans closing indexes of all the brackets
        
        return rec(str,0,str.length()-1);
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends