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
    TreeNode* solveHere(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return NULL;
        
        if(root == p || root == q) return root;
        
        TreeNode* l = solveHere(root->left,p,q);
        TreeNode* r = solveHere(root->right,p,q);
        
        if(l == NULL) return r;
        else if(r == NULL) return l;
        
        return root;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solveHere(root,p,q);
    }
};