class Solution {

    void bfs(vector<vector<int>>& a,vector<int>& vis,int src){
        queue<int> q;
        q.push(src);
        vis[src]=1;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int i=0;i<vis.size();i++){
                if(a[x][i] && !vis[i]){
                    vis[i]=1;
                    q.push(i);
                }
            }
        }
    }

public:

    int findCircleNum(vector<vector<int>>& a) {
        vector<int  >vis(a.size(),0);
        int ct=0;
        for(int i=0;i<a.size();i++){
            if(!vis[i]){
                ct++;
                bfs(a,vis,i);
            }
            
        }
        return ct;
    }
};