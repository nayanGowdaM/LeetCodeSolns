typedef pair<int,pair<int,int>> ppi;
class Solution {
    bool check(int i,int r ,  int j, int c){
        return i>=0 && i<r && j>=0 && j<c;
    }
public:
    int minimumEffortPath(vector<vector<int>>& ht) {
        int m=ht.size(), n=ht[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        dist[0][0]=0;
        priority_queue<ppi,vector<ppi>,greater<ppi>>q;
        q.push({0,{0,0}});
        while(!q.empty()){
            int h=q.top().first,r=q.top().second.first,c=q.top().second.second;
            q.pop();
            if(check(r-1,m,c,n) && max(dist[r][c],abs(ht[r-1][c]-ht[r][c]))<dist[r-1][c]){
                dist[r-1][c]=max(dist[r][c],abs(ht[r-1][c]-ht[r][c]));
                q.push({dist[r-1][c],{r-1,c}});
            }
            if(check(r+1,m,c,n) &&max(dist[r][c],abs(ht[r+1][c]-ht[r][c]))<dist[r+1][c]){
                dist[r+1][c]=max(dist[r][c],abs(ht[r+1][c]-ht[r][c]));
                q.push({dist[r+1][c],{r+1,c}});
            }
            if(check(r,m,c-1,n) &&max(dist[r][c],abs(ht[r][c-1]-ht[r][c]))<dist[r][c-1]){
                dist[r][c-1]=max(dist[r][c],abs(ht[r][c-1]-ht[r][c]));
                q.push({dist[r][c-1],{r,c-1}});
            }
            if(check(r,m,c+1,n) && max(dist[r][c],abs(ht[r][c+1]-ht[r][c]))<dist[r][c+1]){
                dist[r][c+1]=max(dist[r][c],abs(ht[r][c+1]-ht[r][c]));
                q.push({dist[r][c+1],{r,c+1}});
            }
        }
        return dist[m-1][n-1]; 
    }
};