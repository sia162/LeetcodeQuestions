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
        if(root->right == NULL && root->left == NULL) return {{root->val}};
        
        vector<vector<int>> trav;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            
            vector<int> travsub;
            int size = q.size();
            
            for(int i=0;i<size;i++){
                travsub.push_back(q.front()->val);
                if(q.front()->left!=NULL) q.push(q.front()->left);             
                if(q.front()->right!=NULL) q.push(q.front()->right);
                q.pop();
            }
                                    
            trav.push_back(travsub);
        }
                  
        return trav;
        
    }
};
