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
    TreeNode* solveHere(TreeNode* root,int q,int p){
        if(root == NULL) return NULL;
        
        if(q>root->val && p>root->val) 
            return solveHere(root->right,q,p);
        else if(q<root->val && p<root->val)
            return solveHere(root->left,q,p);
        else return root;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode* lca = solveHere(root,q->val,p->val);
        return lca;
        
    }
};