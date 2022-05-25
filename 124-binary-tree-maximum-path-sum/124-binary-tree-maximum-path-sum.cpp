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
    int ms = INT_MIN;
    
    int maxPathSumThroughHeight(TreeNode* root){
        if(root == NULL) return 0;
        
        int ls = max(maxPathSumThroughHeight(root->left),0);
        int rs = max(maxPathSumThroughHeight(root->right),0);
        
        ms = max(ms,root->val + ls+rs);
        
        return root->val + max(ls,rs);
    }
    
    
    
    int maxPathSum(TreeNode* root) {
        
        if(root == NULL) return 0;
        
        maxPathSumThroughHeight(root);
        return ms;
    }
};