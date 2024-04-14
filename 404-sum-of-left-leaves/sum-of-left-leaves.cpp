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
    int solve(TreeNode* root){
        if(!root || (!root->left && !root->right)) return 0;
        if( root->left && ( !root->left->left && !root->left->right)) return root->left->val + solve(root->right);
        return solve( root->left) + solve( root->right);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return solve( root);
    }
};