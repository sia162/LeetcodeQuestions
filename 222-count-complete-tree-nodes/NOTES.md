**Approch 1: TC - 0(N)  | SC - 0(H) - 0(logN)**
​
```
class Solution {
public:
void preorder(TreeNode* root,int& ans){
if(!root) return;
ans++;
preorder(root->left,ans);
preorder(root->right,ans);
}
int countNodes(TreeNode* root) {
if(!root) return 0;
int ans = 0;
preorder(root,ans);
return ans;
}
};
```