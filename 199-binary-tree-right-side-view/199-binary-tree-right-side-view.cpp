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
        map<int,int> nodes;
        //level & nodes->val
        
        queue<pair<TreeNode*,int>> q;
        //for traversal // node & level
        
        q.push({root,0});
        while(!q.empty()){
            auto qele = q.front();
            q.pop();
            TreeNode* n = qele.first;
            int l = qele.second;
            
            nodes[l] = n->val;
            if(n->left) q.push({n->left,l+1});
            if(n->right) q.push({n->right,l+1});
        }
        
        vector<int> ans;
        for(auto it : nodes){
            ans.push_back(it.second);
        }
        
        return ans;
        
    }
};