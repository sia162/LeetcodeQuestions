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
        if(root==NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        int direction = 0;
        // 0 -> right
        // 1 -> left
        
        while(!q.empty()){
            int size = q.size();
            vector<int> temp(size);
            
           for(int i=0;i<size;i++){
                TreeNode* t = q.front();

                int index = direction? size-1-i : i;
                temp[index] = t->val;
                q.pop();

                if(t->left!=NULL) q.push(t->left);
                if(t->right!=NULL) q.push(t->right);

			}
            
            ans.push_back(temp);
            direction = !direction;
        }
        
        return ans;
        
    }
};