class Solution {
public:
    bool check(int i, int r,int j,int c){
        return i>=0 && i<r && j>=0 && j<c;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& a, int sr, int sc, int color) {
        if(a[sr][sc]==color) return a;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int x=a[sr][sc];
        a[sr][sc]=color;
        int m=a.size(), n=a[0].size();
        while(!q.empty()){
            int i=q.front().first,j=q.front().second;
            q.pop();
            if(check(i-1,m,j,n) && a[i-1][j]==x){
                q.push({i-1,j});
                a[i-1][j]=color;
            }
            if(check(i+1,m,j,n) && a[i+1][j]==x){
                q.push({i+1,j});
                a[i+1][j]=color;
            }
            if(check(i,m,j-1,n) && a[i][j-1]==x){
                q.push({i,j-1});
                a[i][j-1]=color;
            }
            if(check(i,m,j+1,n) && a[i][j+1]==x){
                q.push({i,j+1});
                a[i][j+1]=color;
            }
        }
        return a;
    }
};