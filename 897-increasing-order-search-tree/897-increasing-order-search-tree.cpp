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
    void inorder(TreeNode* root,vector<int>& intrav){
        if(root == NULL) return;
        
        inorder(root->left,intrav);
        intrav.push_back(root->val);
        inorder(root->right,intrav);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> intrav;
        
        inorder(root,intrav);
        
        TreeNode* nroot = new TreeNode(intrav[0]);
        TreeNode* temp = nroot;
        
        for(int i=1;i<intrav.size();i++){
            temp->right = new TreeNode(intrav[i]);
            temp = temp->right;
        }
        
        return nroot;
    }
};