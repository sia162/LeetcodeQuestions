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
    
    bool checkIsSymmetrical(TreeNode* left,TreeNode* right){
        if(left==NULL || right == NULL) return right == left;
        
        if(left->val!=right->val) return 0;
        
        return checkIsSymmetrical(left->left,right->right) && 
            checkIsSymmetrical(left->right,right->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return root==NULL || checkIsSymmetrical(root->left,root->right);
    }
};