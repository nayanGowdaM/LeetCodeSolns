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
    void solve( TreeNode* root, int depth, int curDepth, int val){
        if(!root) return ;
        if(depth == curDepth + 1){
            TreeNode *left=new TreeNode(val), *right = new TreeNode(val);
            left->left = root->left;
            right->right = root->right;
            root->left=left;
            root->right = right;
            return ;
        }
        solve( root->left, depth, curDepth+1, val);
        solve(root->right, depth, curDepth+1, val);
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if( depth ==1){
            TreeNode* res = new TreeNode(val);
            res->left=root;
            return res;
        }
        solve(root, depth, 1, val);
        return root;
        
    }
};