class Solution {
    bool bfs(vector<vector<int>>& a, vector<int>& vis, int src){
        queue<int> q;
        q.push(src);
        vis[src]=0;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(int x: a[cur]){
                if(vis[x]==-1){
                    q.push(x);
                    vis[x]=!vis[cur];
                }
                else if(vis[x]==vis[cur]) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& a) {
        vector<int>vis(a.size(),-1);
        for(int i=0;i<a.size();i++){
            if(vis[i]==-1 && !bfs(a,vis, i)) return false; 
        }
        return true;
    }
};