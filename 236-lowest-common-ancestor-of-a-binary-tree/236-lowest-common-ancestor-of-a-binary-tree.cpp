/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool rootToNodePath(TreeNode* root,TreeNode* key,vector<TreeNode*>& ans){
        if(root == NULL) return false;
        ans.push_back(root);
        
        if(root->val == key->val) return true;
        if(rootToNodePath(root->left,key,ans) || rootToNodePath(root->right,key,ans)) return true;
        
        ans.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1;
        vector<TreeNode*> v2;
        
        rootToNodePath(root,p,v1);
        rootToNodePath(root,q,v2);
        
        TreeNode* ans;
        
        for(int i=0,j=0;i<v1.size() && j<v2.size();i++,j++){
            if(v1[i]->val == v2[j]->val) ans = v1[i];
        }
        
        return ans;
    }
};