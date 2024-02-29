

class Solution {
    typedef pair<pair<int,int>,int> ppi;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<ppi, vector<ppi> , greater<ppi>>pq;
        int ans=INT_MAX;
        vector<pair<int,int>> adj[n];
        for( auto x: flights){
            adj[x[0]].push_back({x[1], x[2]});
        }
        vector<int> cost(n, INT_MAX);
        cost[src]=0;
        pq.push({{0,0}, src});
        while(!pq.empty()){
            int vis=pq.top().first.first, dist=pq.top().first.second, node=pq.top().second;
            pq.pop();
            if(vis<=k){
                for( auto x :adj[node] ){
                    int len=dist + x.second;
                    if(len < cost[x.first]){
                        cost[x.first]=len ;
                        pq.push({{vis+1,len},x.first});
                    }
                    
                }
            }
        }
        return cost[dst]==INT_MAX? -1:cost[dst];
    }
};
