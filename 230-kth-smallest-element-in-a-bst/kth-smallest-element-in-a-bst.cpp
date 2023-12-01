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
    int ans;
    void inorder(TreeNode* root , int& k){
        if(!root) return ;
        inorder(root->right, k);
        k--;
        if(!k) ans=root->val;
        inorder(root->left, k);
    }
    int len(TreeNode* root) {
        if(!root) return 0;
        return len(root->left)+len(root->right)+1;
    }
    int kthSmallest(TreeNode* root, int k) {
        int n=len(root);
        k=n-k+1;
        inorder(root,k);
        return ans;
    }
};