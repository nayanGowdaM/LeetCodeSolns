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
    vector<int> v;
    void inorder(TreeNode* root){
        if(!root) return ;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    void CorrInorder(TreeNode* root, int& i){
        if(!root) return ;
        CorrInorder(root->left, i);
        if(root->val!=v[i]) root->val = v[i];
        i++;
        CorrInorder(root->right , i);
    }
    void recoverTree(TreeNode* root) {
        int i=0;
        inorder(root);
        sort(v.begin(),v.end());
        for(auto x: v) cout<<x<<" ";
        CorrInorder(root,i);
        
    }
};