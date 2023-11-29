/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void markParent(unordered_map<TreeNode* ,TreeNode*>& mp, TreeNode* root,unordered_map<TreeNode* , bool>& vis){
        if(!root) return;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            vis[temp]=false;
            if(temp->left) {
                mp[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right){
                mp[temp->right] =temp;
                q.push(temp->right);
            }
        }

    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(!root) return ans;
        unordered_map<TreeNode* , TreeNode* > parent;
        unordered_map<TreeNode* , bool> vis;
        markParent(parent, root,vis);
        queue<TreeNode*  > q;
        vis[target] = true;
        int ct=0;
        q.push(target);
        while(!q.empty()){
            int n=q.size();
            if(ct++==k) break;
            for(int i=0;i<n;i++) {
                TreeNode* cur=q.front();
                q.pop();
                if(cur->left && !vis[cur->left]){
                    vis[cur->left]=true;
                    q.push(cur->left);
                    // cout<<q.back()->val<<" ";
                }
                if(cur->right && !vis[cur->right]){
                    vis[cur->right]=true;
                    q.push(cur->right);
                    // cout<<q.back()->val<<" ";
                }
                if(parent.find(cur)!=parent.end() && !vis[parent[cur]]){
                    vis[parent[cur]]=true;
                    q.push(parent[cur]);
                    // cout<<q.back()->val<<endl;
                }
            }
        }
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            ans.push_back(temp->val);
        }
        return ans;
    }
};