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
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> inorder;
        
        TreeNode* cur = root;
        while(cur!=NULL){
            if(cur->left == NULL){ //case 1
                inorder.push_back(cur->val);
                cur = cur->right;
            }else{
                TreeNode* prev = cur->left;
                while(prev->right && prev->right!=cur){
                    prev = prev->right;
                }
                
                //right == NULL
                if(prev->right == NULL){
                    prev->right = cur; //thread making
                    cur = cur->left;
                }else{ //pointing to root/cur
                    prev->right = NULL;
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
                 
            }//if left exists
        }
        
        return inorder;
        
    }
};