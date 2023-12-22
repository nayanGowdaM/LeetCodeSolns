
class DisjointSet{
    public:
    vector<int> rank,par,size;

    DisjointSet(int n){
        rank.resize(n+1,0);
        par.reserve(n+1);
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
    int removeStones(vector<vector<int>>& stones) {
        int N=stones.size();
        int m=0,n=0;
        for(auto x: stones){
            m=max(m,x[0]);
            n=max(n,x[1]);
        }
        DisjointSet ds(m+n+1);
        unordered_set<int> s;
        for(auto x: stones){
            int row=x[0],col=x[1]+1+m;
            ds.unionByRank(row,col);
            s.insert(row);
            s.insert(col);
        }
        int ct=0;
        for(auto& x: s) if(x==ds.findParent(x)) ct++;
        return N-ct;
    }
};