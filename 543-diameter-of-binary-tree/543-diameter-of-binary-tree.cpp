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
    int height(TreeNode* root){
        if(root == NULL) return 0;
        return 1 +  max(height(root->right),height(root->left));
    }
    
    int diameter = 0;
    void checkLongestRoute(TreeNode* root){
        if(root == NULL) return;
        
        int lh = height(root->left);
        int rh = height(root->right);
        diameter = max(diameter,(lh+rh));
        
        checkLongestRoute(root->left);
        checkLongestRoute(root->right);
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        
        checkLongestRoute(root);
        return diameter;
    }
};