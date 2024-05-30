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
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* start = root;
        TreeNode* node = new TreeNode( val);
        if(!root) return node;
        while((val<root->val && root->left) || ( root->val <= val && root->right)){
            if( val<root->val) root=root->left;
            else root=root->right;
        }
        if( val < root->val) root->left = node;
        else root->right = node;
        return start;
    }
};