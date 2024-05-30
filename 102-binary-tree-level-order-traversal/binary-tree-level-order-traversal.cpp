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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode* > q;
        vector<vector<int>> ans;
        if(!root) return ans;
        TreeNode * node;
        q.push( root);
        while( !q.empty()){
            int k=q.size();
            vector<int> temp;
            while( k--){
                node = q.front();
                q.pop();
                temp.push_back( node->val);
                if( node->left)
                q.push( node->left);
                if( node->right) q.push( node->right);
            }
            ans.push_back( temp);
        }
        return ans;
    }
};