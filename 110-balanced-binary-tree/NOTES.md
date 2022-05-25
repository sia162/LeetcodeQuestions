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
​
​
​
​
**APPROCH 1 | Long Way - Finding Height At Each Step and Checking**
​
```
class Solution {
public:
int height(TreeNode* node){
if(node == NULL) return 0;
return 1+max(height(node->left),height(node->right));
}
bool isBalanced(TreeNode* root) {
if(root == NULL) return 1;
if(root->left == NULL && root->right == NULL) return 1;
int lh = height(root->left);
int rh = height(root->right);
if(abs(lh-rh) > 1) return 0;
return isBalanced(root->left) && isBalanced(root->right);
}
};
```