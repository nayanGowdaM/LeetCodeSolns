class Solution {
    bool dfs( int src, vector<int> adj[], int dest, vector<int>& vis){
        if( src == dest) return true;
        vis[src]= 1;
        for( auto x : adj[src]){
            if( !vis[x] && dfs( x, adj, dest, vis)) return true;
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        for( auto x: edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> vis(n,0);
        return dfs(source, adj, destination , vis);
    }
};