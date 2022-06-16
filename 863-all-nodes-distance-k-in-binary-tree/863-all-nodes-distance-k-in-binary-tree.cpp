/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void parentNodeMark(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parentnode){
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
                TreeNode* n = q.front();
                q.pop();
                
                if(n->left) {q.push(n->left); parentnode[n->left] = n;}
                if(n->right) {q.push(n->right); parentnode[n->right] = n;}
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parentnode;
        parentNodeMark(root,parentnode);
        
        
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        
        int dist = 0;
        
        while(!q.empty()){
            if(dist == k)
                break;
            
            dist++;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* n = q.front();
                q.pop();

                if(n->left && !visited[n->left]) {q.push(n->left); visited[n->left] = true;}
                if(n->right && !visited[n->right]){ q.push(n->right); visited[n->right] = true;}
                
                TreeNode* parent = parentnode[n];
                if(parent && !visited[parent]) {q.push(parent); visited[parent] = true;}
            }
        }
        
        
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        
        return ans;
    }
};