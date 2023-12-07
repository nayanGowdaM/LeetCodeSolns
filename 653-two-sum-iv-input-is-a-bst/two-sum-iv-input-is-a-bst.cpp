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

 class BSTI{
   stack<TreeNode* > stl,str;
   void helpl(TreeNode* root) {
     while(root){
       stl.push(root);
       root=root->left;
     }
   }
   void helpr(TreeNode* root){
     while(root){
       str.push(root);
       root=root->right;
     }
   }
   public:
   BSTI(TreeNode* root){
     helpl(root);
     helpr(root);
   }
   int next(){
     TreeNode* node=stl.top();
     stl.pop();
     helpl(node->right);
     return node->val;
   }
   int prev(){
     TreeNode* node=str.top();
     str.pop();
     helpr(node->left);
     return node->val;
   }
   bool hasnext(){
     return !stl.empty();
   }
   bool hasprev(){
     return !str.empty();
   }
 };
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTI* x=new BSTI(root);
        int a=x->next(),b=x->prev();
        cout<<a<<" "<<b<<" ";
        while(x->hasnext() || x->hasprev()){
          int sum=a+b;
          if(sum==k && a!=b) return true;
          if(sum<k){
            if(x->hasnext()) a=x->next();
            else return false;
          }
          else{
            if(x->hasprev()) b=x->prev();
            else return false;
          }
          cout<<a<<" "<<b<<" ";
        }
        return false;
    }
};