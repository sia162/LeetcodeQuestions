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
    
    void leftsum(TreeNode* root,int& sum, int direction){
        
        if(direction && root->left == NULL && root->right == NULL) {sum+=root->val; return;}
        
        if(root->left) leftsum(root->left,sum,1);
        if(root->right) leftsum(root->right,sum,0);
        
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        
        if(!root) return 0;
        int sum = 0;
        int direction = 0; //1->left and 0->right
        
        leftsum(root,sum,direction);
        return sum;
        
    }
};