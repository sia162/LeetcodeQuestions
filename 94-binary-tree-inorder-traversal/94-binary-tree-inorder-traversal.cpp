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
    
    vector<int> inordertraverse;
//     void inorder(TreeNode* root){
//         if(root == NULL) return;
        
//         inorder(root->left);
//         inordertraverse.push_back(root->val);
//         inorder(root->right);
//     }
    
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        
        stack<TreeNode*> s;
        TreeNode* node = root;
        
        while(true){
             if(node!=NULL){
                 s.push(node);
                 node = node->left;
             }else{
                if(s.empty()) break;
                node = s.top();
                inordertraverse.push_back(node->val); 
                s.pop();
                node = node->right;
             }
        }
     
       
        return inordertraverse;
    }
};