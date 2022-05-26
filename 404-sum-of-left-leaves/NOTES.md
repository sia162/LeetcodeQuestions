**APPROCH 1**
```
class Solution {
public:
int sum = 0;
int sumOfLeftLeaves(TreeNode* root , bool leftSide=false) {
if(root == NULL) return 0;
if(root->left == NULL && root->right == NULL) return leftSide ? root->val : 0;
return sumOfLeftLeaves(root->left,true) + sumOfLeftLeaves(root->right,false);
}
};
```
​
​
​
**APPROCH 2**
​
```
void leftsum(TreeNode* root,int& sum, int direction){
if(direction && root->left == NULL && root->right == NULL) {sum+=root->val; return;}
if(root->left) leftsum(root->left,sum,1);
if(root->right) leftsum(root->right,sum,0);
}
int sumOfLeftLeaves(TreeNode* root) {
if(!root) return 0;
int sum = 0;
int direction = 0; //1->left and 0->right
leftsum(root,sum,direction);
return sum;
}
```
​
​