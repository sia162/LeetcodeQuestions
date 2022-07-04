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


class BSTIterator {
public:
    stack<TreeNode*> st;
    bool flag;
    // flag == true   | before()
    // flag == false  | next()
    
    BSTIterator(TreeNode* root,bool isFlag){
        flag = isFlag;
        pushAll(root);
    }
    
    int bstNextBefore(){
        TreeNode* n = st.top();
        st.pop();
        
        if(flag){
            pushAll(n->left);
        }else{
            pushAll(n->right);
        }
        return n->val;
    }
    
private:
    void pushAll(TreeNode* node){
        while(node!=NULL){
            st.push(node);
            if(flag) node = node->right;
            else node = node->left;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        
        BSTIterator next(root,false);
        BSTIterator before(root,true);
        
        int i = next.bstNextBefore();
        int j = before.bstNextBefore();
        
        
        while(i<j){
            if(i+j == k) return true;
            else if(i+j > k) j = before.bstNextBefore();
            else i = next.bstNextBefore();
        }
        
        return false;
    }
};