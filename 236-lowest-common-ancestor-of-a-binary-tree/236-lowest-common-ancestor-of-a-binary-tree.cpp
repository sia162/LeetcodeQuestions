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
    
    TreeNode* rootToNodePath(TreeNode* root,TreeNode* B,TreeNode* C){ 
        if(!root || root == B || root == C) return root;
        
        TreeNode* left = rootToNodePath(root->left,B,C);
        TreeNode* right = rootToNodePath(root->right,B,C);
        if(left == NULL) return right;
        else if(right == NULL) return left;
            
        return root;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        TreeNode* ans = rootToNodePath(root,p,q);
      
        return ans;
        
    }
};