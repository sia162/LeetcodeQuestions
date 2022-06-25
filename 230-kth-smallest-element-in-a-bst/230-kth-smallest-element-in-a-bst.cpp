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
    void inorderTra(TreeNode* root, int k,int& count,int& ans){
        if(root == NULL) return;
        
        inorderTra(root->left,k,count,ans);
        
        count++;
        if(count == k){
            ans = root->val;
        }
        
        inorderTra(root->right,k,count,ans);
        return;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int ans,count = 0;
        
        inorderTra(root,k,count,ans);
        
        return ans;
    }
};