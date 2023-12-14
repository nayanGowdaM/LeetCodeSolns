class Solution {
    vector<int> res;
    bool dfs(int src, vector<vector<int>>& adj, vector<int>& vis,vector<int>& path){
        vis[src]=1;
        path[src]=1;
        for(auto x: adj[src]){
            if(path[x] )  return false;
            else if(!vis[x] && !dfs(x,adj,vis,path)) return false;
            
        }
        path[src]=0;
        res.push_back(src);
        return true;
    }

public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> vis(n,0);
        vector<int> path(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<pre.size();i++){
            adj[pre[i][0]].push_back(pre[i][1]);
        }
        for(int i=n-1;i>=0;i--){
            if(!vis[i] && !dfs(i,adj,vis,path)) return {};
        }
        return res;
    }
};