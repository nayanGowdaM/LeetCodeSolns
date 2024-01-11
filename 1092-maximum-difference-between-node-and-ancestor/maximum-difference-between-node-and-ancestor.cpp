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
    int ct=0;
    void find(TreeNode* root, int mn,int mx){
        if(!root) return ;
        ct=max(ct,max( abs(mn-root->val),abs(mx-root->val)));
        mx=max(mx,root->val);
        mn=min(mn,root->val);
        find(root->left, mn,mx);
        find(root->right, mn,mx);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        find(root, root->val,root->val);
        return ct;
    }
};