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
    
    int sum = 0;
    int sumOfLeftLeaves(TreeNode* root,int direction = 0) {
        if(root==NULL) return 0;
        
        if(direction && root->left == NULL && root->right == NULL) sum += root->val;
            
        sumOfLeftLeaves(root->left,1);
        sumOfLeftLeaves(root->right,0); 
        
        return sum;
    }
};