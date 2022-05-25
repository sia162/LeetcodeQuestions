vector<vector<int>> ans;
if(root==NULL) return {};
​
​
queue<TreeNode*> q;
q.push(root);
​
int direction = 0; //rightToLeft = 1 and leftToRight = 0
while(!q.empty()){
int size = q.size();
vector<int> temp(size);
​
for(int i=0;i<size;i++){
TreeNode* t = q.front();
​
int index = direction? size-1-i : i;
temp[index] = t->val;
q.pop();
​
if(t->left!=NULL) q.push(t->left);
if(t->right!=NULL) q.push(t->right);
​
}
​
ans.push_back(temp);
direction = !direction;
}
​
return ans;