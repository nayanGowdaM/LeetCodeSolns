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
        if(!root ) return 0;
        // if(!root->left && !root->right) return root->val;
        int left = max(0, solve(root->left));
        int right = max(0, solve(root->right));
        ans = max( ans,left + right + root->val);
        return root->val + max( left, right) ;
    }
    int maxDown(TreeNode* root, int &ans){
        if(!root) return 0;
        int l=max(0,maxDown(root->left,ans));
        int r=max(0,maxDown(root->right,ans));
        ans=max(ans,l+r+root->val);
        return max(r,l)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        return  max(ans, solve(root));
    }
};



