
class Disjoint{
    
    public:
    vector<int> par, rank;
    Disjoint(int n){
        par.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) par[i]=i;
    }

    int findParent(int node){
        if(node==par[node]) return node ;
        return par[node]=findParent(par[node]);

    }

    void Union(int u,int v){
        int upU=findParent(u),upV=findParent(v);
        if(upU==upV) return;
        if(rank[upU] < rank[upV] )  par[upU] =upV;
        else if(rank[upV] < rank[upU]) par[upV]=upU;
        else{
            par[upU]=upV;
            rank[upV]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& conn) {
        Disjoint ds(n);
        for(auto x: conn){
            ds.Union(x[0],x[1]);
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int par=ds.findParent(i);
            mp[par]=(mp.find(par)==mp.end())?0:mp[par]+1;
        }
        int disjointSet=mp.size(),reqEdges=0;
        for(auto& x: mp){
            reqEdges+=x.second;
        }
        int totalEdges=conn.size();
        if(totalEdges-reqEdges>=disjointSet-1) return disjointSet-1;
        else return -1;
    }
};