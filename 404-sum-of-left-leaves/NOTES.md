```
class Solution {
public:
int sum = 0;
int sumOfLeftLeaves(TreeNode* root , bool leftSide=false) {
if(root == NULL) return 0;
if(root->left == NULL && root->right == NULL) return leftSide ? root->val : 0;
return sumOfLeftLeaves(root->left,true) + sumOfLeftLeaves(root->right,false);
}
};
```
​
​