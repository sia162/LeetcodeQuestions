***APPROCH 1 | T - 0(N)***
​
```
class Solution {
public:
TreeNode* solveHere(TreeNode* root,int p,int q){
if(!root || root->val == p || root->val == q) return root;
TreeNode* left = solveHere(root->left,p,q);
TreeNode* right = solveHere(root->right,p,q);
if(left == NULL) return right;
else if(right == NULL) return left;
return root;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
TreeNode* lca = solveHere(root,p->val,q->val);
return lca;
}
};
```
​
***Approch 2***
​