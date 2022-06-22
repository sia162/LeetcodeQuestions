**Recursive and iterative**
```
class Solution {
public:
vector<int> inordertraverse;
//     void inorder(TreeNode* root){
//         if(root == NULL) return;
//         inorder(root->left);
//         inordertraverse.push_back(root->val);
//         inorder(root->right);
//     }
vector<int> inorderTraversal(TreeNode* root) {
if(root == NULL) return {};
stack<TreeNode*> s;
TreeNode* node = root;
while(true){
if(node!=NULL){
s.push(node);
node = node->left;
}else{
if(s.empty()) break;
node = s.top();
inordertraverse.push_back(node->val);
s.pop();
node = node->right;
}
}
return inordertraverse;
}
};
```
​
​