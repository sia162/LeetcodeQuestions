```
class Solution {
public:
int maxpathsum = INT_MIN;
int MaxPathSumUsingHeightTraversal(TreeNode* root){
if(root == NULL) return 0;
int lsum = max(0,MaxPathSumUsingHeightTraversal(root->left));
int rsum = max(0,MaxPathSumUsingHeightTraversal(root->right));
maxpathsum = max(maxpathsum,(lsum + rsum + root->val));
return root->val + max(rsum,lsum);
}
int maxPathSum(TreeNode* root) {
if(root == NULL) return 0;
MaxPathSumUsingHeightTraversal(root);
return maxpathsum;
}
};
```