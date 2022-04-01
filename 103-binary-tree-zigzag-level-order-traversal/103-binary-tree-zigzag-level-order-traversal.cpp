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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return {};
        
        
        queue<TreeNode*> q;
        q.push(root);
        
        int direction = 0; //right = 1 and left = 0
        while(!q.empty()){
            vector<int> temp;
            int size = q.size();
            
            for(int i=0;i<size;i++){
                TreeNode* t = q.front();
                temp.push_back(t->val);
                q.pop();
                
                if(t->left!=NULL) q.push(t->left);
                if(t->right!=NULL) q.push(t->right);
            
            }
            
            if(!direction) ans.push_back(temp);
            else{ 
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
            }
            direction = 1 - direction;
          
        }
        
        return ans;
        
    }
};