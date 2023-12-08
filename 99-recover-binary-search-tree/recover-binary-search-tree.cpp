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
    TreeNode* first, *prev, *mid, *last;
public:

    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        if(first->val>root->val){
            if(!prev){
                prev=first;
                mid=root;
            }
            else last=root;
        }
        first=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        prev=mid=last=NULL;
        first= new TreeNode(INT_MIN);
        inorder(root);
        if(prev && last) swap(prev->val, last->val);
        else swap(prev->val, mid->val);
    }
};