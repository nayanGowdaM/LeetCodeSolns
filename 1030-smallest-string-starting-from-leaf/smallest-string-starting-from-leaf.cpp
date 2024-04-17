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
    string ans="~";
    void solve( TreeNode* root , string s){
        if(!root) return ;
        if(!root->left && !root->right) ans = min( ans, string( 1, root->val + 'a') + s);
        solve( root->left, string( 1, root->val + 'a') + s);
        solve( root->right , string(1, root->val+'a')+s);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        solve(root, "" );
        return ans;
    }
};