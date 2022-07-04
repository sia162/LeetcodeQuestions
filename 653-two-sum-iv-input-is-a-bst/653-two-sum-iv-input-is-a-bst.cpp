/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    stack<TreeNode*> st1;
    stack<TreeNode*> st2;
    
    int next(){
        TreeNode* node = st1.top();
        int val = node->val;
        st1.pop();
        
        while(node!=NULL){
            node = node->right;
            while(node!=NULL){
                st1.push(node);
                node = node->left;
            }
        }
       
        return val;
    }
    
    
    int before(){
        TreeNode* node = st2.top();
        int val = node->val;
        st2.pop();
        
        while(node!=NULL){
            node = node->left;
            while(node!=NULL){
                st2.push(node);
                node = node->right;
            }
        }
       
        return val;
    }
    
    
    bool findTarget(TreeNode* root, int k) {
      
        //FOR NEXT()
        TreeNode* temp = root;
        while(temp!=NULL){
            st1.push(temp);
            temp = temp->left;
        }
        
        //FOR BEFORE()
        temp = root;
        while(temp!=NULL){
            st2.push(temp);
            temp = temp->right;
        }
        
        
        int i,j;
        i=next();
        j=before();
        
        while(i<j){
            if(i+j == k) return true;
            else if(i+j > k) j = before();
            else i = next();
        }
        
        return false;
    }
};