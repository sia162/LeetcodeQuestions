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
    void inorder(TreeNode* root,vector<int> &inordertrav){
        if(root == NULL) return;
        
        inorder(root->left,inordertrav);
        inordertrav.push_back(root->val);
        inorder(root->right,inordertrav);
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> inordertrav;
        inorder(root,inordertrav);
        unordered_map<int,int> m;
        
        for(int i=0;i<inordertrav.size();i++){
            if(m.find(k - inordertrav[i]) != m.end()) return true;
            
            m[inordertrav[i]] = i;
        }
        
        
        return false;
    }
};