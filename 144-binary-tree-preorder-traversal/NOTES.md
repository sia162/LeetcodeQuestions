```
vector<int> prevect;
if(root == NULL) return prevect;
stack<TreeNode*> st;
st.push(root);
while(!st.empty()){
TreeNode* top = st.top();
st.pop();
prevect.push_back(top->val); //printed the top of stack
if(top->right!=NULL) st.push(top->right); //stored firstly right into stack
if(top->left!=NULL) st.push(top->left); // stored secondly left into stack
}
return prevect;
```