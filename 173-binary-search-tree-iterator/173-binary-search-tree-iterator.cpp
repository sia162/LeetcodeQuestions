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
    vector<int> inordert;
    int i = 0;
    
    void inorder(TreeNode* root){
        if(root == NULL) return;
        
        inorder(root->left);
        inordert.push_back(root->val);
        inorder(root->right);
    }
    
    
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        int ans = inordert[i];
        i++;
        return ans;
    }
    
    bool hasNext() {
        bool ans = true;
        if(i>=inordert.size()) 
            ans = false;
        
        return ans;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */