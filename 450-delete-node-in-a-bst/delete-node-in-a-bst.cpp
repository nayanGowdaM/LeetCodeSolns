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

    TreeNode* lastRight( TreeNode* root){
        if(!root) return root;
        while(root->right) root=root->right;
        return root;
    }

    TreeNode* helper( TreeNode* root){
        TreeNode* lastR = lastRight( root->left);
        if( !lastR) return root->right;
        else{
            lastR->right = root->right;
            return root->left;
        }
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* head = root;
        if(!root) return root;
        if(root->val == key) return helper( root);
        while(root){
            if( root->val > key){
                if(root->left && root->left->val == key){
                    root->left = helper( root->left);
                    return head;
                }
                else root=root->left;
            }
            else {
                if(root->right && root->right->val == key){
                    root->right = helper( root->right);
                    return head;
                }
                else root=root->right;
            }
        }
        return head;
    }
};