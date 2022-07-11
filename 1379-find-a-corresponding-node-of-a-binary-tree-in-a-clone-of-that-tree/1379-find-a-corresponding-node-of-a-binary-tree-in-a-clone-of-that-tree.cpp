/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void inorder(TreeNode* root,TreeNode* t,TreeNode* &ans){
        if(root == NULL) return;
        
        inorder(root->left,t,ans);
        if(root->val == t->val){
            ans = root;
        }
        inorder(root->right,t,ans);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans = NULL;
        inorder(cloned,target,ans);
        
        return ans;
    }
};