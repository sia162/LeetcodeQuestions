***APPROCH 1***
```
class Solution {
public:
bool rootToNodePath(TreeNode* root,vector<TreeNode*>& v,int B){
if(!root) return false;
v.push_back(root);
if(root->val == B) return true;
if(rootToNodePath(root->left,v,B) || rootToNodePath(root->right,v,B)) return true;
v.pop_back();
return false;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
vector<TreeNode*> v1;
vector<TreeNode*> v2;
rootToNodePath(root,v1,p->val);
rootToNodePath(root,v2,q->val);
TreeNode* ans;
for(int i=0,j=0;i<v1.size() && j<v2.size();i++,j++){
if(v1[i]->val == v2[j]->val) ans = v1[i];
}
return ans;
}
};
```
​
​
​
​
***APPROCH 2***
​
```
class Solution {
public:
TreeNode* rootToNodePath(TreeNode* root,TreeNode* B,TreeNode* C){
if(!root || root == B || root == C) return root;
TreeNode* left = rootToNodePath(root->left,B,C);
TreeNode* right = rootToNodePath(root->right,B,C);
if(left == NULL) return right;
else if(right == NULL) return left;
return root;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
​
TreeNode* ans = rootToNodePath(root,p,q);