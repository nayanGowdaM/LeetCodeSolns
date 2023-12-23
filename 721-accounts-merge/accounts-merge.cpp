
class DisjointSet{
    vector<int> rank,par,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        par.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++) par[i]=i;
    }

    int findParent(int node){
        if(node==par[node]) return node;
        return par[node]=findParent(par[node]);
    }

    void unionByRank(int u,int v) {
        int upU=findParent(u),upV=findParent(v);
        if(upU==upV) return ;

        if(rank[upU]<rank[upV]) par[upU]=upV;
        else if(rank[upV]<rank[upU]) par[upV]=upU;
        else {
            par[upV]=upU;
            rank[upU]++;
        }
    }

    void unionBySize(int u, int v){
        int upU=findParent(u),upV=findParent(v);
        if(upU==upV) return;
        if(size[upU]<size[upV] ) {
            par[upU]=upV;
            size[upV]+=size[upU];
        }
        else{
            par[upV]=upU;
            size[upU]+=size[upV];
        }
    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        int n=acc.size();
        map<string,int>mp;
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            int m=acc[i].size();
            for(int j=1;j<m;j++){
                if(mp.find(acc[i][j])==mp.end()){
                    mp[acc[i][j]]=i;
                }
                else{
                    ds.unionByRank(i,mp[acc[i][j]]);
                }
            }
        }

        unordered_map<int,vector<string>>ans;
        for(auto& x: mp){
            int idx=ds.findParent(x.second);
            ans[idx].push_back(x.first);
        }
        // for(auto& x: ans) sort(x.second.begin(), x.second.end());
        vector<vector<string>>res;
        for(auto x: ans){
            vector<string> temp;
            int idx=x.first;
            temp.push_back(acc[idx][0]);
            temp.insert(temp.end(),x.second.begin(),x.second.end());
            res.push_back(temp);
        }
        return res;
    }
};