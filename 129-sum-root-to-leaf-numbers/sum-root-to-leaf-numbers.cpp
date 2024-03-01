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
    int ans=0;
    void solve(TreeNode* root,int& res){
        if(!root) return ;
        if(!root->left && !root->right){
            ans+=res*10+root->val;
            return ;
        }
        res=res*10+root->val;
        if(root->left) solve(root->left, res);
        if(root->right) solve(root->right, res);
        res=(res-root->val)/10;
    }
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int res=0;
        solve(root,res );
        return ans;
    }
};