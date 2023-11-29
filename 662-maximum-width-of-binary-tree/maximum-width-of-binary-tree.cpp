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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode* ,long long>> q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            long long first, last, mmin=q.front().second;
            for(int i=0;i<n;i++){
                int cur_id=q.front().second-mmin;
                TreeNode* temp=q.front().first;
                q.pop();
                if(i==0) first=cur_id;
                if(i==n-1) last=cur_id;
                if(temp->left) q.push({temp->left,(long long)cur_id*2+1});
                if(temp->right) q.push({temp->right, (long long)cur_id*2+2});

            }
            if(ans<(last-first+1)) ans=(last-first+1);
        }
        return ans;
    }
};