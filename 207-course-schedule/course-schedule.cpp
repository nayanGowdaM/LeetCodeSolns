class Solution {
    bool dfs(vector<int> adj[], vector<int>& vis, vector<int>& path, int src){
        vis[src]=1;
        path[src]=1;
        for(auto x: adj[src]){
            if(path[x]) return false;
            if(!vis[x] && !dfs(adj, vis, path, x)) return false;
        }
        path[src]=0;
        return true;
    }
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n],vis(n,0),path(n,0);
        for(auto x: pre){
            adj[x[0]].push_back(x[1]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i] && !dfs(adj,vis, path, i)) return false;
        }
        return true;
    }
};