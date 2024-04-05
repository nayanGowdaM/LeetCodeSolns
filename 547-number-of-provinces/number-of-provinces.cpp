class Solution {
    void dfs( int src, vector<int>& vis, vector<vector<int>>& g, int n){
        vis[src]=1;
        for( int i =0;i<n;i++){
            if( !vis[i] && g[src][i]) dfs( i, vis, g, n);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& g) {
        int ans=0;
        int n= g.size();
        vector<int> vis(n,0 );

        for( int i=0;i<n;i++){
            if( !vis[i]){
                dfs( i, vis, g, n);
                ans++;
            }
        }
        return ans;
        
    }
};