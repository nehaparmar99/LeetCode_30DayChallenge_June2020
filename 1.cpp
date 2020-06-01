/*
Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return NULL;
        else{
            struct TreeNode *temp;
            root->left=invertTree(root->left);
            root->right=invertTree(root->right);
            temp=root->left;
            root->left=root->right;
            root->right=temp;
        }
        return root;
    }
};
