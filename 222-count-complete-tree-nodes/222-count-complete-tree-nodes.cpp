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
    void preorder(TreeNode* root,int& ans){
        if(!root) return;
        
        ans++;
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        int ans = 0;
        preorder(root,ans);
        return ans;
    }
};