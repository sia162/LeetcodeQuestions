```
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
public:
void convertToMirror(TreeNode* leftside){
if(leftside == NULL) return;
else {
TreeNode* temp;
convertToMirror(leftside->left);
convertToMirror(leftside->right);
temp = leftside->left;
leftside->left = leftside->right;
leftside->right = temp;
}
return;
}
bool issame(TreeNode* a,TreeNode* b){
if(a == NULL && b == NULL) return true;
if(a!=NULL && b!=NULL && a->val == b->val  && issame(a->left,b->left) && issame(a->right,b->right)){
return true;