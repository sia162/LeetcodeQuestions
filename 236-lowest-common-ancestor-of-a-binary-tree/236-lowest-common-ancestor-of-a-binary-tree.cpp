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
    bool rootToNodePath(TreeNode* root,TreeNode* node,vector<TreeNode*> &path){
        if(root == NULL) return false;
        path.push_back(root);
        
        if(root->val == node->val) return true;
        
        if(rootToNodePath(root->left,node,path)) return true;
        if(rootToNodePath(root->right,node,path)) return true;
        
        path.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> vp;
        vector<TreeNode*> vq;
        
        rootToNodePath(root,p,vp);
        rootToNodePath(root,q,vq);
        
        TreeNode* ans = NULL;
        for(int i=0;i<vp.size() && i<vq.size();i++){
            if(vp[i]->val == vq[i]->val) ans = vp[i];
        }
        
        if(ans) return ans;
        return NULL;
        
    }
};