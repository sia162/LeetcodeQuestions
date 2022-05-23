```
stack<TreeNode*> st;
TreeNode* temp = root;
while(true){
if(temp!=NULL){
st.push(temp);
temp = temp->left;
}else{
if(st.empty()) break;
temp = st.top();
st.pop();
inordertraverse.push_back(temp->val);
temp = temp->right;
}
}
return inordertraverse;
```