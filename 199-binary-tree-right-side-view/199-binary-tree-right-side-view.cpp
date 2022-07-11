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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        // reverse inorder -> right root left
        map<int,int> rviewMap;
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            TreeNode* n = q.front().first;
            int l = q.front().second;
            q.pop();
            
            rviewMap[l] = n->val;
            if(n->left) q.push({n->left,l+1});
            if(n->right) q.push({n->right,l+1});
        }
        
        vector<int> rview;
        
        for(auto t: rviewMap){
            rview.push_back(t.second);
        }
        
        return rview;
    } 
};