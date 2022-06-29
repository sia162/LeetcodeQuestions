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
    TreeNode* solveHere(vector<int> preorder, int preStart, int preEnd, vector<int> inorder, int inStart, int inEnd, unordered_map<int,int> inMap){
        if(inStart>inEnd || preStart>preEnd) return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;
        
        root->left = solveHere(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,inMap);
        root->right = solveHere(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,inMap);
        return root;
        
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder;
        
        for(auto val:preorder) inorder.push_back(val);
        sort(inorder.begin(),inorder.end());
        
        unordered_map<int,int> inMap;
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]] = i;
        }
        
        TreeNode* root = solveHere(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
        return root;
    }
};