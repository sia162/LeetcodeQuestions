***TC - 0(N) and SC - 0(N)***
```
void inorder(TreeNode* root,vector<int>& intrav){
if(root == NULL) return;
inorder(root->left,intrav);
intrav.push_back(root->val);
inorder(root->right,intrav);
}
TreeNode* increasingBST(TreeNode* root) {
vector<int> intrav;
inorder(root,intrav);
TreeNode* nroot = new TreeNode(intrav[0]);
TreeNode* temp = nroot;
for(int i=1;i<intrav.size();i++){
temp->right = new TreeNode(intrav[i]);
temp = temp->right;
}
return nroot;
}
```
​
***TC - 0(N) and SC - 0(1)***