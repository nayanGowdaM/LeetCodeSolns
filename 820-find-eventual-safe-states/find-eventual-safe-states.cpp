class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        vector<int> adj[g.size()],indegree(g.size(),0);
        for(int i=0;i<g.size();i++){
            for(auto x: g[i]){
                adj[x].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        vector<int> ans;
        for(int i=0;i<g.size();i++) if(!indegree[i]) q.push(i);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            ans.push_back(x);
            for(auto node: adj[x]){
                indegree[node]--;
                if(!indegree[node]) q.push(node);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};