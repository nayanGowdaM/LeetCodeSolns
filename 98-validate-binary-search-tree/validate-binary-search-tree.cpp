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
    int leftMost(TreeNode* root){
        while(root->left) root=root->left;
        return root->val;
    }

    int rightMost(TreeNode* root){
        while(root->right) root=root->right;
        return root->val;
    }
    bool isValidBST(TreeNode* root) {
        if(!root || !root->left && !root->right) return true;
        if((root->left && root->left->val >= root->val) || ( root->right  && root->right->val <= root->val)) return false;
        if(root->right && root->left)
        return isValidBST(root->left)&& isValidBST(root->right) && (root->val<leftMost(root->right))&& (root->val>rightMost(root->left));
        else if(root->left)return isValidBST(root->left)  && (root->val>rightMost(root->left));
        else if(root->right) return isValidBST(root->right) && (root->val<leftMost(root->right));
        else return true;
    }
};