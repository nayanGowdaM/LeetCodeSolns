class Solution {
    int find_parent( int node, vector<int>& par, vector<int>& rank){
        if(node == par[node] ) return node;
        else return par[node]= find_parent(par[node], par, rank);
    }

    void Union( int u, int v, vector<int>& par, vector<int>& rank){
        int up_u=find_parent( u, par, rank), up_v=find_parent( v, par, rank);
        if( up_u == up_v) return;
        else if( rank[up_u] > rank[up_v]) par[up_v] = up_u;
        else if(rank[up_v] > rank[up_u]) par[up_u] = up_v;
        else {
            par[up_v] = up_u;
            rank[up_u]++;
        }
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        vector<int>par(n+1), rank(n+1,0);
        for(int i=0;i<=n;i++) par[i] = i;
        for(auto x: edges){
            Union( x[0], x[1], par, rank);
        }
        return find_parent(src, par, rank) == find_parent( dest, par, rank);
    }
};