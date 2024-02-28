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
    int ans=INT_MIN;
    int solve(TreeNode* root){
        if(!root || (!root->left && !root->right)) return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        if( root->left && root->right){
            ans=max(ans, left + right +2);
            
        }
        else{
            ans=max(ans, 1 + left + right);
             
        }
        return max(left, right) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return max(ans, solve(root));
    }
};