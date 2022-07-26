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
    TreeNode* rootToNodePathWithValueReturn(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root == p) return p;
        if(root == q) return q;
        if(root == NULL) return NULL;
        
        TreeNode* left = rootToNodePathWithValueReturn(root->left,p,q);
        TreeNode* right = rootToNodePathWithValueReturn(root->right,p,q);
        if(left == NULL) return right;
        else if(right == NULL) return left;
            
        return root;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         return rootToNodePathWithValueReturn(root,p,q); 
    }
};