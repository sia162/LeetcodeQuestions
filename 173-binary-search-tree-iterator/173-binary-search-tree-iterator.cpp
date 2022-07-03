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
    
    void insertLeftNodes(TreeNode* root){
         while(root!=NULL){
            st.push(root);
            root = root->left;
        }
    }
    
    BSTIterator(TreeNode* root) {
       insertLeftNodes(root);
    }
    
    int next() {
        int ans = st.top()->val;
        TreeNode* node = st.top();
        st.pop();
        
        if(node->right!=NULL){
            node = node->right;
            insertLeftNodes(node);
        }
        return ans;
    }
    
    bool hasNext() {
        if(!st.empty()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */