class Solution {
    void dfs(int src, vector<int> adj[],vector<int>& vis){
        vis[src]=1;
        int n=vis.size();
        for(auto i: adj[src]){
            if(!vis[i]) dfs(i,adj,vis);
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& conn) {
        int edges=conn.size();
        if(edges<n-1) return -1;
        vector<int>adj[n];
        for(auto x: conn){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int disjointSet=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                disjointSet++;
            }
        }
        return disjointSet-1;
    }
};