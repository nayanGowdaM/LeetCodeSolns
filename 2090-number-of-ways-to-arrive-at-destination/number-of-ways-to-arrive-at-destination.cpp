typedef pair<long long ,long long> pr;
const int M = 1e9+7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pr> adj[n];
        for(auto x: roads){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        priority_queue<pr , vector<pr>,greater<pr>>q;
        vector<long long> dist(n,LLONG_MAX),path(n,0);
        dist[0]=0;
        path[0]=1;
        q.push({0,0});
        while(!q.empty()){
            long long  d=q.top().first, node=q.top().second;
            q.pop();
            for(auto x: adj[node]){
                if((long)d+(long)x.second < (long)dist[x.first]){
                    dist[x.first]=d+x.second;
                    q.push({dist[x.first],x.first});
                    path[x.first]=path[node];
                }
                else if(d+x.second==dist[x.first]) path[x.first]=((long)path[x.first]+(long)path[node])%M;
            }
        }
        return path[n-1]%M;
    }
};