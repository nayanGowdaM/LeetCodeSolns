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

    string lex(string& a , string& b){
        int n = min( a.size(), b.size());
        int i=0;
        while( i<n){
            if(a[i] == b[i]) i++;
            else {
                if( a[i] > b[i]) return b;
                else return a;
            }
        }
        if( a.size() < b.size()) return a;
        else return b;

    }

    string solve( TreeNode* root, string prev ){
        char ch = 'a' + root->val;
        if(!root->left  && !root->right) return string(1,ch) + prev;
        string left="", right="";
         
        if(root->left && root->right){
            left = solve( root->left, string(1,ch)) +prev;
            right = solve(root->right ,  string(1,ch)) + prev;
            string ans = lex( left, right);
            cout<<ans;
           
            return ans;
        }
        else if(root->left){
            left = solve( root->left,  string(1,ch));
            // char ch = root->val + 'a';
            return left + prev;
        }
        else{
            right = solve(root->right,  string(1,ch));
            return right +prev;
        }

    }
public:
    string smallestFromLeaf(TreeNode* root) {
        if(!root) return "";
        return solve( root, "");
    }
};