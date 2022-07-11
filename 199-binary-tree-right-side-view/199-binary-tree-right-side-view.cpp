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
    void inorder(TreeNode* root,vector<int>& rview,int level){
        if(root==NULL) return;
        
        if(level == rview.size()) rview.push_back(root->val);
        inorder(root->right,rview,level+1);
        inorder(root->left,rview,level+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        // reverse inorder -> right root left
        vector<int> rview;
    
        inorder(root,rview,0);
        
        return rview;
    } 
};