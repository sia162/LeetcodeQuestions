```
if(root==NULL) return NULL;
if(root->val == val) return root;
if(val > root->val){
return searchBST(root->right,val);
}else{
return searchBST(root->left,val);
}
```