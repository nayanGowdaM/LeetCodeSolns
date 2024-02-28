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
        pair<int,int> solve(TreeNode* root){
        if(!root->left && !root->right) return make_pair(1,root->val);
        pair<int,int> a, b;
        if(root->left && root->right){
            a=solve(root->left);
            b=solve(root->right);
            if(a.first >= b.first) return make_pair(a.first+1, a.second);
            else return make_pair(b.first+1, b.second);
        }
        else if( !root->left){
            b=solve(root->right);
            return make_pair(b.first+1, b.second);
        }
        else {
            a=solve( root->left);
            return make_pair(a.first+1, a.second);
        }
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        auto ans = solve( root);
        return ans.second;
    }
};