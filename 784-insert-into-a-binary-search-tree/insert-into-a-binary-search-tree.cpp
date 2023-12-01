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
        TreeNode* node=new TreeNode(val),*start=root;
        TreeNode* prev;
        if(!root) return node;
        while(root){
            prev=root;
            if(root->val<val) root=root->right;
            else root=root->left;
        }
        if(prev->val<val) prev->right=node;
        else prev->left=node;
        return start;
    }
};