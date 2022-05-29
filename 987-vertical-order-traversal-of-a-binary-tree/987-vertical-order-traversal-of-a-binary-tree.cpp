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
        // verticles  //level & nodes on that level in sorted order
        
        queue<pair<TreeNode*,pair<int,int>>> q; //queue for traversal around the tree
                // Nodes    //verticle and level
        
        //the main idea is to store all the nodes in a verticle order-wise with use of map (map will sort the verticle -->){...,-2,-1,0,1,2,...}
        //first we travel the 0 verticle and add it further we move to the left side node oviously the left side verticle nodes will come
        //first in the verticle order traversal so we have to decrease the verticle by 1 so that in the ma it gets sorted above.
        //when we move towards right we increase verticle by 1 so that in map they get sorted later in the order.
        //now for the level we also need a map so in-case we have 2 nodes in the same level we what them sorted as well. if we did not
        //want this we could have used just a vector we put nodes of same verticle in one place.
        
        q.push({root,{0,0}});
        
        while(!q.empty()){
            auto qelement = q.front();
            q.pop();
            TreeNode* n = qelement.first;
            int v = qelement.second.first;
            int l = qelement.second.second;
            
            nodes[v][l].insert(n->val);
            if(n->left) q.push({n->left,{v-1,l+1}});
            if(n->right) q.push({n->right,{v+1,l+1}});
        }
        
        
        vector<vector<int>> ans;
        for(auto melement : nodes){
            vector<int> vcol;
            for(auto minner : melement.second){
                vcol.insert(vcol.end(),minner.second.begin(),minner.second.end());
            }
            
            ans.push_back(vcol);
        }
        
        return ans;
        
    }
};