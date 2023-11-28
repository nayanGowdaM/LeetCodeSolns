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
    int maxDown(TreeNode* root, int &ans){
        if(!root) return 0;
        int l=max(0,maxDown(root->left,ans));
        int r=max(0,maxDown(root->right,ans));
        ans=max(ans,l+r+root->val);
        return max(r,l)+root->val;
    }
    int maxPathSum(TreeNode* root) {

        int ans=INT_MIN;
        maxDown(root,ans);
        return ans;
    }
};