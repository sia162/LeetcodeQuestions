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
    TreeNode* rootToNodePath(TreeNode* root,int a,int b){
        if(root == NULL || root->val == a || root->val == b) return root;
        
        TreeNode* left = rootToNodePath(root->left,a,b);
        TreeNode* right = rootToNodePath(root->right,a,b);
        
        if(left == NULL) return right;
        else if(right == NULL) return left;
        
        return root;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca = rootToNodePath(root,p->val,q->val);
       
        return lca;
    }
};