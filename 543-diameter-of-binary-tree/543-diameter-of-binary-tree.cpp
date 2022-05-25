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
    
    int diameter = 0;
    
    int heightDiameter(TreeNode* root){
        
        if(root == NULL) return 0;
        
        int lh = heightDiameter(root->left);
        int rh = heightDiameter(root->right);
        
        diameter = max(diameter,lh+rh);    
        return 1+max(lh,rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root == NULL) return 0;
    
        heightDiameter(root);
        
        return diameter;
        
    }
};