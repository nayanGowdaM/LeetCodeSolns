#include<bits/stdc++.h>
using namespace std;


class Disjoint{
    public:
    vector<int> size, par;
    Disjoint(int n){
        size.resize(n+1,1);
        par.resize(n+1);
        for(int i=0;i<=n;i++) par[i]=i;
    }

    int findParent(int node){
        if(node==par[node]) return node;
        return par[node]=findParent(par[node]);
    }
    void Union(int u,int v){
        int upU=findParent(u),upV=findParent(v);
        if(upU==upV) return ;
        if(size[upV]<size[upU]){
            par[upV]=upU;
            size[upU]+=size[upV];
        }
        else{
            par[upU]=upV;
            size[upV]+=size[upU];
        }
    }
};

class Solution {
private:
    bool isValid(int newr, int newc, int n) {
        return newr >= 0 && newr < n && newc >= 0 && newc < n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        Disjoint ds(n * n);
        // step - 1
        for (int row = 0; row < n ; row++) {
            for (int col = 0; col < n ; col++) {
                if (grid[row][col] == 0) continue;
                int dr[] = { -1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                for (int ind = 0; ind < 4; ind++) {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if (isValid(newr, newc, n) && grid[newr][newc] == 1) {
                        int nodeNo = row * n + col;
                        int adjNodeNo = newr * n + newc;
                        ds.Union(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        // step 2
        int mx = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) continue;
                int dr[] = { -1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                set<int> components;
                for (int ind = 0; ind < 4; ind++) {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if (isValid(newr, newc, n)) {
                        if (grid[newr][newc] == 1) {
                            components.insert(ds.findParent(newr * n + newc));
                        }
                    }
                }
                int sizeTotal = 0;
                for (auto it : components) {
                    sizeTotal += ds.size[it];
                }
                mx = max(mx, sizeTotal + 1);
            }
        }
        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            mx = max(mx, ds.size[ds.findParent(cellNo)]);
        }
        return mx;
    }
};
