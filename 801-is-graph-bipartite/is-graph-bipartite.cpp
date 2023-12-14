class Solution {
    bool dfs(unordered_set<int>& s1,unordered_set<int>& s2, vector<vector<int>>& a,vector<int>& vis, int src){
        vis[src]=1;
        for(auto x: a[src]){
            if(!vis[x] && !dfs(s2,s1,a,vis,x)) return false;
            if(s1.find(x)!=s1.end()) return false;
            s2.insert(x);
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_set<int>s1,s2;
        vector<int> vis(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            if(!vis[i] && !dfs(s1,s2,graph,vis,i)) return false;
        }
        return true;
    }
};