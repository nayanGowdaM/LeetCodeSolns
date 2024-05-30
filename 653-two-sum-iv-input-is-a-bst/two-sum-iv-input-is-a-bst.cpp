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
    bool twoSum( TreeNode* root, int k, unordered_set<int>& st){
        if( !root) return false;
        if( st.find( k-root->val) !=st.end()) return true;
        st.insert( root->val);
        return twoSum( root->left, k,st) || twoSum( root->right, k, st);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        return twoSum( root, k, st);
    }
};