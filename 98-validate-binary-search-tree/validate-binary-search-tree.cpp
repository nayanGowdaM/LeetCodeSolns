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
    bool isValid(TreeNode* root, pair<long long ,long long > p){
        if(!root ) return true;
        return root->val<p.second && root->val>p.first && isValid(root->left, {p.first,root->val}) && isValid(root->right, {root->val, p.second});
    }
    bool isValidBST(TreeNode* root) {
        if(!root || !root->left && !root->right) return  true;
        return isValid(root, {LLONG_MIN,LLONG_MAX});
    }
};