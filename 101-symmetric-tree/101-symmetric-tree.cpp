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
    void rtraverse(TreeNode* root,vector<int>& v){
        if(root == NULL) {
            v.push_back(NULL);
            return;
        }
        
        v.push_back(root->val);
        rtraverse(root->left,v);
        rtraverse(root->right,v);
    }
    
    void ltraverse(TreeNode* root,vector<int>& v){
        if(root == NULL){ 
            v.push_back(NULL);
            return;}
        
        v.push_back(root->val);
        ltraverse(root->right,v);
        ltraverse(root->left,v);
    }
    
    bool isSymmetric(TreeNode* root) {
        
        vector<int> tleft;
        vector<int> tright;
        
        ltraverse(root->left,tleft);
        rtraverse(root->right,tright);
        
        if(tleft.size()!=tright.size()) return 0;
        
        for(int i=0;i<tleft.size();i++){
            if(tleft[i]!=tright[i])
                return 0;
        }
        
        return 1;
        
    }
};