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
    vector<int> postt;
    // void postorder(TreeNode* root){
    //     if(root==NULL) return;
    //     postorder(root->left);
    //     postorder(root->right);
    //     postt.push_back(root->val);
    // }
    
    vector<int> postorderTraversal(TreeNode* root) {
       
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        if(root == NULL) return postt;
        
        st1.push(root);
        while(!st1.empty()){
            TreeNode* topst1 = st1.top();
            st1.pop();
            
            
            st2.push(topst1);
            
            if(topst1->left!=NULL) st1.push(topst1->left);
            if(topst1->right!=NULL) st1.push(topst1->right);
        }
        
        while(!st2.empty()){
            postt.push_back(st2.top()->val);
            st2.pop();
        }
        return postt;
    }
};