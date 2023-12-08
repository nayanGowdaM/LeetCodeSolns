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
    void preorder(TreeNode* root, string& s){
      if(!root) return ;
      if(!root->left && !root->right){
        s+="("+to_string(root->val)+")";
        return ;
      }
      s+="("+to_string(root->val);
      if(!root->left) s+="()";
      else
      preorder(root->left, s);
      preorder(root->right, s);
      s+=")";
    }
    string tree2str(TreeNode* root) {
      string s="";
      preorder(root, s);
      return s.substr(1,s.size()-2);
    }
};