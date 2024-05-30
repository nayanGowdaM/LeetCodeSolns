/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool validate( TreeNode* root, long long  l, long long  r){
        if(!root) return true;
        if( root->val >l && root->val <r) return validate(root->left,l, root->val) && validate( root->right, root->val, r);
        else return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        long long l= -1ll + INT_MIN, r=1ll + INT_MAX;
        return validate(root,l,r);
    }
};