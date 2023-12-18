typedef pair<int,int> p;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        vector<pair<int,int>>adj[n];
        for(auto x: times) adj[x[0]-1].push_back({x[1]-1,x[2]});
        for(int i=0;i<n ;i++){
            cout<<i<<"->";
            for(auto x:adj[i]) cout<<"("<<x.first<<" "<<x.second<<")";
            cout<<endl;
        }
        src--;
        vector<int>cost(n,INT_MAX);
        priority_queue<p,vector<p>,greater<p>> q;
        q.push({0,src});
        cost[src]=0;
        while(!q.empty()){
            int dist=q.top().first, node=q.top().second;
            q.pop();
            if(dist>cost[node]) continue;
            for(auto x: adj[node]){
                if(dist+x.second < cost[x.first]){
                    cost[x.first]=dist+x.second;
                    q.push({cost[x.first],x.first});
                }
            }
        }
        for(auto x: cost) cout<<x<<" ";
        int m=*max_element(cost.begin(),cost.end());
        if(m==INT_MAX) return -1;
        return m;
    }
};