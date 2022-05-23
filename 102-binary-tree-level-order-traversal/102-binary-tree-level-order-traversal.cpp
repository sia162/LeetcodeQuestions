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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root == NULL) return {};
        if(root->left == NULL && root->right == NULL) return {{root->val}};
        
        vector<vector<int>> bfs;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            vector<int> trav;
            int size = q.size();
            
            for(int i=0;i<size;i++){
                trav.push_back(q.front()->val);
                
                if(q.front()->left!=NULL) q.push(q.front()->left);
                if(q.front()->right!=NULL) q.push(q.front()->right);
                
                q.pop();
            }
            
            bfs.push_back(trav);
            
        }
        
        return bfs;
        
    }
};