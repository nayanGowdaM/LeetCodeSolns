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
    vector<int>dia(TreeNode* root){
        if(!root) return {0,0};
        vector<int> l=dia(root->left);
        vector<int> r=dia(root->right);
        int maxC=max(l[1],r[1]);
        int height=max(l[0],r[0])+1;
        int curC=l[0]+r[0];
        maxC=max(maxC,curC);
        return {height,maxC};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        vector<int> ans=dia(root);
        return ans[1];
    }
};