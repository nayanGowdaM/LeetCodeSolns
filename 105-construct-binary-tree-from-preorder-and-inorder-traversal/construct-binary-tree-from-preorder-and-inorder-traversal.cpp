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
    int i;
    TreeNode* generate(vector<int>& pre,vector<int>& in, int l, int r){
        int j;
        for( j=l;j<=r;j++ ) if(pre[i]==in[j]) break;
        int p=j;
        TreeNode* root=new TreeNode(pre[i]);
        i++;
        if(l==p) root->left=NULL;
        else root->left=generate(pre,in,l,p-1);
        if(r==p) root->right=NULL;
        else root->right=generate(pre,in,p+1,r);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return generate(preorder,inorder, 0,preorder.size()-1);
    }
};