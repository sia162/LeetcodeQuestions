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
    
    vector<int> v1;
    vector<int> v2;
    
    void leafArray(TreeNode* root,vector<int>& v){
        if(root == NULL) return;
        
        if(root->left == NULL && root->right == NULL)
          {  v.push_back(root->val); return;}
        
        leafArray(root->left,v);
        leafArray(root->right,v);
        return;
        
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        leafArray(root1,v1);
        leafArray(root2,v2);
        
         if(v1.size()!=v2.size()) return false;
        
           for(int i=0,j=0;i<v1.size();i++,j++){
                if(v1[i]!=v2[j]) return false;
            }
        
        
        return true;
    }
};