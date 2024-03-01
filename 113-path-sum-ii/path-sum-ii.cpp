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
    vector<vector<int>> res;
    void solve(TreeNode* root, int t, vector<int>& ans){
        if(!root ) return ;
        if(!root->left  && !root->right){
            if(t == root->val){
                ans.push_back(root->val);
                res.push_back(ans);
                ans.pop_back();
            }
            return ;
        }
        ans.push_back(root->val);
        solve(root->left, t-root->val, ans);
        solve(root->right, t-root->val, ans);
        ans.pop_back();

    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        vector<int> ans;
        solve(root, t, ans);
        return res;
    }
};