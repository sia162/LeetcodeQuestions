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
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last = NULL;
    int violation = 1;
    TreeNode* prev = NULL;
    
    void inorder(TreeNode* root){
        if(root == NULL) return;
        
        inorder(root->left);
        
        if(prev!=NULL && root->val<prev->val && violation == 1){
            first = prev;
            middle = root;
            violation++;
        }else if(prev!=NULL  && root->val<prev->val && violation == 2){
            last = root;
            violation++;
        }
        prev = root;
        
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        
        inorder(root);
        if(last == NULL) swap(first->val,middle->val);
        else swap(first->val,last->val);
    
    }
};