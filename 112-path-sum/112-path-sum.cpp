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
    
    int solveWithInorder(TreeNode* root,int targetSum){
        if(root==NULL) return 0;
        if(root->left == NULL && root->right == NULL && targetSum-root->val == 0) return 1;

        
        return (solveWithInorder(root->left,targetSum-root->val) ||
        solveWithInorder(root->right,targetSum-root->val));
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root == NULL) return 0;
        return solveWithInorder(root,targetSum);
        
    }
};