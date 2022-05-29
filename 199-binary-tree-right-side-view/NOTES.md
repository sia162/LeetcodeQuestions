**APPROCH 1: LEVEL ORDER TRAVERSAL (more space complexity)**
​
```
vector<int> rightSideView(TreeNode* root) {
if(root == NULL) return {};
map<int,int> nodes;
//level & nodes->val
queue<pair<TreeNode*,int>> q;
//for traversal // node & level
//the idea if simple as we did for the top view and bottom view. here is stolen from bottom view as we keep inserting elements
// or nodes into the map untill we get the last value/nodes on that particular level. Here we use simple level order traversal. and
//consider level nodes. untill last on the level is reached.
q.push({root,0});
while(!q.empty()){
auto qele = q.front();
q.pop();
TreeNode* n = qele.first;
int l = qele.second;
nodes[l] = n->val;
if(n->left) q.push({n->left,l+1});
if(n->right) q.push({n->right,l+1});
}
vector<int> ans;
for(auto it : nodes){
ans.push_back(it.second);
}
return ans;
}
```