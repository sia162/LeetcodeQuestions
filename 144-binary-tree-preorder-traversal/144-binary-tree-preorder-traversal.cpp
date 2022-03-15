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
    
    vector<int> prevect;
    void preorder(TreeNode* root){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){prevect.push_back(root->val); return;}
        
        prevect.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
        return;
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        
        preorder(root);
        return prevect;
    }
};