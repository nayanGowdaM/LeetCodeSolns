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
    int j;
    TreeNode* generate(vector<int>& in, vector<int>& post , int l, int r){
        int i;
        for( i=l;i<=r;i++) if(post[j]==in[i]) break;
        j--;
        int p=i;
        TreeNode* root=new TreeNode(in[p]);
        if(r==p) root->right=NULL;
        else root->right=generate(in , post, p+1,r);
        if(l==p) root->left=NULL;
        else root->left=generate(in,post,l,p-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        j=inorder.size()-1;
        return generate(inorder,postorder,0,j);
    }
};