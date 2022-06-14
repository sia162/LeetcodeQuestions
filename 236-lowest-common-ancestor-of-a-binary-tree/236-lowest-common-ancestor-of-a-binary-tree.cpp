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
    
    bool rootToNodePath(TreeNode* root,vector<TreeNode*>& v,int B){
        if(!root) return false;
        v.push_back(root);
        
        if(root->val == B) return true;
        
        if(rootToNodePath(root->left,v,B) || rootToNodePath(root->right,v,B)) return true;
        
        v.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector<TreeNode*> v1;
        vector<TreeNode*> v2;
        
        rootToNodePath(root,v1,p->val);
        rootToNodePath(root,v2,q->val);
        
        TreeNode* ans;
        for(int i=0,j=0;i<v1.size() && j<v2.size();i++,j++){
            if(v1[i]->val == v2[j]->val) ans = v1[i];
        }
        
        return ans;
        
    }
};