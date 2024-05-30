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
    void inorder( TreeNode* root, int& k, int& ans){
        if(!root || k<=0) return ;
        inorder( root->left, k, ans);
        if( k==1 ) ans = root->val;
        k--;
        inorder( root->right,k, ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        inorder( root, k, ans);
        return ans;
    }
};