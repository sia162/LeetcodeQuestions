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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int,map<int,multiset<int>>> nodes;
        // verticle  //level, all nodes that that level
        
        queue<pair<TreeNode*,pair<int,int>>> q;
            // node         verticle,level
        
        
        q.push({root,{0,0}});
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* n = p.first;
            int v = p.second.first;
            int l = p.second.second;
            
            nodes[v][l].insert(n->val);
            
            if(n->left) q.push({n->left,{v-1,l+1}});
            if(n->right) q.push({n->right,{v+1,l+1}});
        }
        
        
        vector<vector<int>> ans;
        
        for(auto mapitem : nodes){
            vector<int> col;
            for(auto t : mapitem.second){
                col.insert(col.end(),t.second.begin(),t.second.end());
            }
            
            ans.push_back(col);
        }
        
        return ans;
    }
};