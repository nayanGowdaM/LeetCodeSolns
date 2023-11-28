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

    vector<pair<pair<int,int>,int>>v;
    static bool cmp(pair<pair<int,int>,int>& a, pair<pair<int,int>,int>& b){
        if(a.first.first==b.first.first && a.first.second==b.first.second ) return a.second<b.second;
        if(a.first.second==b.first.second) return a.first.first<b.first.first;
        return a.first.second<b.first.second;
    }

    
    void func(int row, int col, TreeNode* root){
        if(!root) return ;
        v.push_back({{row,col},root->val});
        func(row+1,col-1,root->left);
        func(row+1,col+1,root->right);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        func(0,0,root);
        sort(v.begin(),v.end(),cmp);
        for(auto x: v) cout<<x.first.first<<" " <<x.first.second<<' '<<x.second<<endl;
        int n=v.size(),i=0;
        vector<vector<int>>ans;
        while(i<n){
            int col=v[i].first.second;
            vector<int>temp;
            while(i<n && v[i].first.second==col){
                temp.push_back(v[i].second);
                i++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};