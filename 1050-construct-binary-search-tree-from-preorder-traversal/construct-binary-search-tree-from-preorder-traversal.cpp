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
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int n=pre.size(),i=1;
        TreeNode* root=new TreeNode(pre[0]),*dummy=root,*temp;
        stack<TreeNode*>st;
        st.push(root);
        while(i<n){
            if(st.top()->val > pre[i]){
                root->left= new TreeNode(pre[i]);
                st.push(root->left);
                root=root->left;
            }
            else{
                temp=st.top();
                st.pop();
                while(!st.empty() && st.top()->val < pre[i]){
                    temp=st.top();
                    st.pop();
                }
                temp->right=new TreeNode(pre[i]);
                root=temp->right;
                st.push(root);
            }
            i++;
        }
        return dummy;
    }
};