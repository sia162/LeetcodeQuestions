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
    void solveHere(TreeNode* root,string s,vector<string> &ans){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            // s.push_back(root->val + '0');
           int val = root->val;
        string valstr = std::to_string(val);
        
        s = s+ valstr;
            
            ans.push_back(s);
            return;
        }
        
        // s.push_back(root->val + '0');
        int val = root->val;
        string valstr = std::to_string(val);
        
        s = s+ valstr;
        
        s.push_back('-');
        s.push_back('>');
        solveHere(root->left,s,ans);
        solveHere(root->right,s,ans);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        
        solveHere(root,"",ans);
        
        return ans;
    }
};