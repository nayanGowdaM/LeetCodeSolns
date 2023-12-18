typedef pair<pair<int,int> , int> ppi;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dest, int k) {
        vector<pair<int,int>> adj[n];
        for(auto x: f){
            adj[x[0]].push_back({x[1],x[2]});
        }
        priority_queue<ppi, vector<ppi>, greater<ppi>>q;
        vector<int>cost(n,INT_MAX);
        cost[src]=0;
        q.push({{0,0},src});
        int ans=INT_MAX;
        while(!q.empty()){
            int vis=q.top().first.first, c=q.top().first.second , node=q.top().second;
            q.pop();
            if(dest==node) ans=min(ans,c) ;
           
                for(auto x: adj[node]){
                    if(c+x.second < cost[x.first] && vis<=k){
                        cost[x.first]=c+x.second;
                        q.push({{vis+1,cost[x.first]},x.first});
                    }
                }
            
        }
        for(auto x: cost) cout<<x<< " ";
        if(ans==INT_MAX)
        return -1;
        return ans;
    }
};