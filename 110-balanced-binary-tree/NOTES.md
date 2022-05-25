```
if(root == NULL)return 0;
int lh = heightCheckBalance(root->left);
if(lh == -1) return -1;
int rh = heightCheckBalance(root->right);
if(rh == -1) return -1;
if(abs(lh-rh)>1) return -1;
return max(lh,rh) + 1;
}
bool isBalanced(TreeNode* root) {
return heightCheckBalance(root) != -1;
}
```