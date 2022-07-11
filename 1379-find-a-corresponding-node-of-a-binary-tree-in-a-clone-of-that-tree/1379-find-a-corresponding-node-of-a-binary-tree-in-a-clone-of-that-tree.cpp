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
     void inorder(TreeNode* o, TreeNode* c,TreeNode*& ans,TreeNode* target) {
        if (o != NULL) {
            inorder(o->left, c->left,ans,target);
            if (o == target) {
                ans = c;    
            }
            inorder(o->right, c->right,ans,target);    
        }
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans = NULL;
        inorder(original,cloned,ans,target);
        
        return ans;
    }
};